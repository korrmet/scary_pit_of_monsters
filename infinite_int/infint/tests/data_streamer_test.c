#include <stdio.h>
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
  if (del(MAX_STREAMS_NUM) < 0) { passed_counter++; } else { printf("fail\n"); }

  printf("-->delete uncreated id\n"); tests_counter++;
  if (del(created + 1) < 0) { passed_counter++; } else { printf("fail\n"); }

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
