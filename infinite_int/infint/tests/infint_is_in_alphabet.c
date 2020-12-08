#include <stdio.h>
#define INFINT_PERR_ENABLE
#define INFINT_PWRN_ENABLE
#define INFINT_PMSS_ENABLE
#define INFINT_PDBG_ENABLE
#include "../infint.c"

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0;

  printf("-->check arguments (null alphabet pointer)\n"); tests_counter++;
  if (infint_is_in_alphabet(0, 
                            NULL, 
                            INFINT_SKIP_SYMBOLS_LEN) == -1) 
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->check arguments (null alphabet pointer)\n"); tests_counter++;
  if (infint_is_in_alphabet(0,
                            infint_skip_symbols,
                            0) == -1)
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->check valid input symbol (space)\n"); tests_counter++;
  if (infint_is_in_alphabet(' ', 
                            infint_skip_symbols,
                            INFINT_SKIP_SYMBOLS_LEN) == 1)
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->check valid input symbol (tab)\n"); tests_counter++;
  if (infint_is_in_alphabet('\t', 
                            infint_skip_symbols,
                            INFINT_SKIP_SYMBOLS_LEN) == 1)
  { passed_counter++; } else { printf("fail\n"); }

  printf("-->check invalid input symbol (new line)\n"); tests_counter++;
  if (infint_is_in_alphabet('\n', 
                            infint_skip_symbols,
                            INFINT_SKIP_SYMBOLS_LEN) == 0)
  { passed_counter++; } else { printf("fail\n"); }

  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  if (tests_counter > passed_counter) { result = -1; }
  return result; }
