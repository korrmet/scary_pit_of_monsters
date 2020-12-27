#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

  printf("-->simple insert in start of stream\n"); tests_counter++;
  { int fail = 0;
    if (pos(STREAM_MEM_POS__START, 0, created) < 0) 
    { printf("can't move positon in stream\n"); fail = 1; }
    uint32_t sample = 0xdeadbeef;
    if (wr(&sample, sizeof(sample), STREAM_WR_MODE__INSERT, created) < 0)
    { printf("can't write in stream\n"); fail = 1; }
    if (pos(STREAM_MEM_POS__START, 0, created) < 0) 
    { printf("can't move positon in stream\n"); fail = 1; }
    uint8_t readen[8] = {}; int res = rd(readen, sizeof(readen), created);
    if (res < 0)
    { printf("can't read from stream\n"); fail = 1; }
    else if (res != 8)
    { printf("incorrect bytes num readen\n"); fail = 1; }
    uint32_t expected[2] = { 0xdeadbeef, 0x12345678 }; 
    if (memcmp(readen, expected, 8) != 0)
    { printf("readen unexpected data\n"); 
      printf("  expected: "); 
      uint8_t* exp = (uint8_t*) expected;
      for (int i = 0; i < 8; i++) { printf("%02x", exp[i]); } printf("\n");
      printf("  readen:   ");
      for (int i = 0; i < 8; i++) { printf("%02x", readen[i]); } printf("\n");
      fail = 1; }
    if (!fail) { passed_counter++; } }

  printf("-->simple insert in middle of stream\n"); tests_counter++;
  { int fail = 0;
    if (pos(STREAM_MEM_POS__START, 3, created) < 0)
    { printf("can't move position in stream\n"); fail = 1; }
    uint8_t sample = 0xaa;
    if (wr(&sample, sizeof(sample), STREAM_WR_MODE__INSERT, created) < 0)
    { printf("can't write in stream\n"); fail = 1; }
    if (pos(STREAM_MEM_POS__START, 0, created) < 0) 
    { printf("can't move positon in stream\n"); fail = 1; }
    uint8_t readen[9] = {}; int res = rd(readen, sizeof(readen), created);
    if (res < 0) { printf("can't read from stream\n"); fail = 1; }
    else if (res != 8) { printf("incorrect bytes num readen\n"); fail = 1; }
    uint8_t expected[9] = 
      { 0xef, 0xbe, 0xad, 0xaa, 0xde, 0x78, 0x56, 0x34, 0x12 };
    if (memcmp(readen, expected, 9) != 0)
    { printf("readen incorrect data\n");
      printf("  expected: ");
      for (int i = 0; i < 9; i++) { printf("%02x", expected[i]); } printf("\n");
      printf("  readen:   ");
      for (int i = 0; i < 9; i++) { printf("%02x", readen[i]); } printf("\n");
      fail = 1; }
    if (!fail) { passed_counter++; } }

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
