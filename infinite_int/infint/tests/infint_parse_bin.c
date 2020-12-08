#include <stdio.h>
#include <stdint.h>
#define INFINT_PERR_ENABLE
#define INFINT_PWRN_ENABLE
#define INFINT_PMSS_ENABLE
#define INFINT_PDBG_ENABLE
#include "../infint.c"

NEW(infint, test);
uint8_t array[10] = {};

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0;

  printf("-->valid call of binary parser\n"); tests_counter++;
  test__class._private.mem = array; 
  if (infint_parse_bin(test, "0b 0101 0101 1010 1010") == 0)
  { passed_counter++; } else { printf("fail\n"); }

  for (int i = 0; i < 10; i++)
  { printf("%02x ", array[i]); }
  printf("\n");

  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  if (tests_counter > passed_counter) { result = -1; }
  return result; }
