#include <stdlib.h>
#include <string.h>
#include "data_streamer.h"

typedef struct //stream_t
{ void* start;
  void* current;
  void* end;
} stream_t;
stream_t streams_pool[MAX_STREAMS_NUM] = {};

int rd(void* ptr, unsigned int len, unsigned int id) 
{ if (ptr == NULL)          { return -1; }
  if (id < 1)               { return -1; } id--;
  if (id > MAX_STREAMS_NUM) { return -1; }

  char* _ptr    = (char*)ptr;
  char* current = (char*)streams_pool[id].current;
  char* start   = (char*)streams_pool[id].start;
  char* end     = (char*)streams_pool[id].end;
  char* buf     = (char*)ptr;

  int readen = 0;
  for (int i = 0; i < len; i++)
  { if (current > end) { break; }
    *_ptr = *current; _ptr++; current++; readen++; }

  return readen; }

int wr(void* ptr, unsigned int len, int mode, unsigned int id)
{ if (ptr == NULL)                    { return -1; }
  if (mode > STREAM_WR_MODE__REPLACE) { return -1; }
  if (id < 1)                         { return -1; } id--;
  if (id > MAX_STREAMS_NUM)           { return -1; } 

  switch (mode)
  { case STREAM_WR_MODE__INSERT: 
    { int siz = streams_pool[id].end - streams_pool[id].start;
      char* new_start   = malloc(siz + len); 
      if (new_start == NULL) { return -1; }
      char* new_end     = new_start + siz + len;
      char* new_current = new_start + (streams_pool[id].current - 
                                       streams_pool[id].start);
      
      memcpy(new_start, streams_pool[id].start, new_current - new_start);
      char* insertion_end = new_current + len;
      memcpy(insertion_end, streams_pool[id].current, len);

      free(streams_pool[id].start);
      streams_pool[id].start   = (void*)new_start;
      streams_pool[id].current = (void*)new_current;
      streams_pool[id].end     = (void*)new_end;
    } break;
    case STREAM_WR_MODE__REPLACE: 
    { if (streams_pool[id].current + len > streams_pool[id].end)
      { void* new_start = 
          realloc(streams_pool[id].start,
                  streams_pool[id].current - streams_pool[id].start + len); 
        void* new_current = new_start + (streams_pool[id].current -
                                         streams_pool[id].end);
        void* new_end     = new_current + len; 
      
        streams_pool[id].start   = new_start;
        streams_pool[id].current = new_current;
        streams_pool[id].end     = new_end; }
    } break;
    default: return -1; } 

  memcpy(streams_pool[id].current, ptr, len);
  
  return len; }

int rm(int len, int id)
{ if (id < 1)               { return -1; } id--;
  if (id > MAX_STREAMS_NUM) { return -1; }

  if (streams_pool[id].current + len > streams_pool[id].end)
  { len = streams_pool[id].end - streams_pool[id].current; }

  memmove(streams_pool[id].current, streams_pool[id].current + len,
          streams_pool[id].end - streams_pool[id].current - len);
  
  void* new_start = 
    realloc(streams_pool[id].start,
                           streams_pool[id].end - streams_pool[id].start - len);
  if (new_start == NULL) { return -1; } 

  void* new_current = 
    new_start + (streams_pool[id].current - streams_pool[id].start);

  void* new_end = 
    new_start + (streams_pool[id].end - streams_pool[id].start - len);
                         
  streams_pool[id].start   = new_start;
  streams_pool[id].current = new_current;
  streams_pool[id].end     = new_end;

  return 0; }

int pos(int pos, int shift, unsigned int id)
{ if (id < 1)               { return -1; } id--;
  if (id > MAX_STREAMS_NUM) { return -1; }
  
  switch (pos)
  { case STREAM_MEM_POS__START: 
      streams_pool[id].current = streams_pool[id].start; break;
    case STREAM_MEM_POS__END:   
      streams_pool[id].current = streams_pool[id].end;   break;
    case STREAM_MEM_POS__CURRENT: break;
    default: return -1; }

  streams_pool[id].current += shift;
  if (streams_pool[id].current > streams_pool[id].end) 
  { streams_pool[id].current = streams_pool[id].end; } 
  if (streams_pool[id].current < streams_pool[id].start)
  { streams_pool[id].current = streams_pool[id].start; } 

  return 0; }

unsigned int crt(void)
{ for (int i = 0; i < MAX_STREAMS_NUM; i++) 
  { if (streams_pool[i].start == NULL) 
    { streams_pool[i].start   = malloc(1);
      if (streams_pool[i].start == NULL) { return 0; }
      
      streams_pool[i].current = streams_pool[i].start; 
      streams_pool[i].end     = streams_pool[i].start;
      
      return ++i; } } 
  return 0; }

int del(int id)
{ if (id < 1)                         { return -1; } id--;
  if (id > MAX_STREAMS_NUM)           { return -1; }
  if (streams_pool[id].start == NULL) { return -1; }
  
  free(streams_pool[id].start); 
  streams_pool[id].current = NULL; streams_pool[id].end     = NULL;
  
  return 0; }
