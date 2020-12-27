#include <stdio.h>
#include <stdint.h>
#include "data_streamer.h"

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0; 

  unsigned int created;
  printf("-->simple create\n"); tests_counter++;
  created = crt();
  if (created != 0) { passed_counter++; } else { printf("fail\n"); }

  printf("-->delete zero id\n"); tests_counter++;
  if (del(0) < 0) { passed_counter++; } else { printf("fail\n"); }

  printf("-->delete too high id\n"); tests_counter++;
  if (del(MAX_STREAMS_NUM + 1) < 0) 
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->delete uncreated id\n"); tests_counter++;
  if (del(created + 1) < 0) { passed_counter++; } else { printf("fail\n"); }
  
  printf("-->write by NULL pointer\n"); tests_counter++;
  if (wr(NULL, 0, STREAM_WR_MODE__INSERT, created) >= 0)
  { printf("fail\n"); } else { passed_counter++; }

  printf("-->write undefined mode\n"); tests_counter++;
  { uint32_t sample = 0x12345678;
    if (wr(&sample, sizeof(sample), 2, created) > 0)
    { printf("fail\n"); } else { passed_counter++; } }

  printf("-->write uncreated id\n"); tests_counter++;
  { uint32_t sample = 0x12345678;
    if (wr(&sample, sizeof(sample), STREAM_WR_MODE__INSERT, created + 1) >= 0)
    { printf("fail\n"); } else { passed_counter++; } }

  printf("-->simple write\n"); tests_counter++;
  { uint32_t sample = 0x12345678;
    int res = wr(&sample, sizeof(sample), STREAM_WR_MODE__INSERT, created);
    if (res < 0) { printf("false error result\n"); }
    else if (res != sizeof(sample)) { printf("incorrect written byte num\n"); }
    else { passed_counter++; } }
  
  printf("-->change position incorrect point\n"); tests_counter++;
  if (pos(3, 0, created) >= 0) { printf("fail\n"); } else { passed_counter++; }

  printf("-->change position too high id\n"); tests_counter++;
  if (pos(STREAM_MEM_POS__START, 0, MAX_STREAMS_NUM + 1) >= 0)
  { printf("fail\n"); } else { passed_counter++; }

  printf("-->simple change position\n"); tests_counter++;
  if (pos(STREAM_MEM_POS__START, 0, created) < 0)
  { printf("fail\n"); } else { passed_counter++; }

  printf("-->simple read\n"); tests_counter++;
  { uint32_t sample = 0;
    int res = rd(&sample, sizeof(sample), created);
    if (res < 0) { printf("false error result\n"); }
    else if (res != sizeof(sample)) { printf("incorrect readen byte num\n"); }
    else if (sample != 0x12345678)  { printf("readen wrong data\n"); }
    else { passed_counter++; } }

  printf("-->simple delete\n"); tests_counter++;
  if (del(created) < 0) { printf("fail\n"); } else { passed_counter++; } 

  printf("-->create overflow\n"); tests_counter++;
  { unsigned int ids[MAX_STREAMS_NUM + 1];
    for (int i = 0; i < MAX_STREAMS_NUM + 1; i++) { ids[i] = crt(); }
    int fail = 0;
    for (int i = 0; i < MAX_STREAMS_NUM; i++)
    { if (ids[i] == 0) { printf("fail\n"); fail = 1; break; } }
    if (ids[MAX_STREAMS_NUM] != 0) { printf("fail\n"); fail = 1; }
    for (int i = 0; i < MAX_STREAMS_NUM; i++) 
    { if (del(ids[i]) < 0) { printf("fail\n"); fail = 1; } }
    if (!fail) { passed_counter++; } }

  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  if (tests_counter > passed_counter) { result = -1; }
  return result; }
