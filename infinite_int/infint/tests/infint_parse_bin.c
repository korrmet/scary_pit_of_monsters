#include <stdio.h>
#include <stdint.h>
#define INFINT_PERR_ENABLE
#define INFINT_PWRN_ENABLE
#define INFINT_PMSS_ENABLE
#define INFINT_PDBG_ENABLE
#include "../infint.c"
#include "data_streamer.h"

NEW(infint, test);
uint8_t array[10] = {};

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0;

  test__class._private.id = crt();

  printf("-->valid call of binary parser\n"); tests_counter++;
  if (infint_parse_bin(test, "0011 1100 1111 1111 1010 1010") == 0)
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->examine memory after parsing\n"); tests_counter++;
  { int fail = 0;
    uint8_t buf[80] = {}; int size = 0;
    size = rd(buf, sizeof(buf), test__class._private.id);
    if (size < 0) { printf("fail, incorrect reading\n"); fail = 1; }
    if (size != 4) 
    { printf("fail, wrong size of data readen (%d, must be 4)\n", size); 
      fail = 1; }
    if (*((uint32_t*)buf) != 0x003CFFAA)
    { printf("fail, unexpcted result\n");
      printf("must be: AA FF 3C\n");
      printf("as is:   ");
      for (int i = 0; i < size; i++) { printf("%02x  ", buf[i]); }
      printf("\n"); 
      fail = 1; } 
    if (!fail) { passed_counter++; } }

  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  if (tests_counter > passed_counter) { result = -1; }
  return result; }
