#include <stdlib.h>
#include "data_streamer.h"

typedef struct //stream_t
{ void* start;
  void* current;
  void* end;
} stream_t;
stream_t streams_pool[MAX_STREAMS_NUM] = {};

int rd(void* ptr, unsigned int len, unsigned int id) 
{}

int wr(void* ptr, unsigned int len, int mode, unsigned int id)
{}

int rm(int len, int id)
{}

int pos(int pos, int shift, unsigned int id)
{}

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
{ if (id < 1)                             { return -1; }
  if (streams_pool[id - 1].start == NULL) { return -1; }
  free(streams_pool[id - 1].start); 
  streams_pool[id - 1].current = NULL; streams_pool[id - 1].end     = NULL;
  return 0; }
