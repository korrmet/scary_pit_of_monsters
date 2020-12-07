#include <stdio.h>
#define INFINT_PRINTF printf
#define INFINT_PERR_ENABLE
#define INFINT_PWRN_ENABLE
#define INFINT_PMSS_ENABLE
#define INFINT_PDBG_ENABLE
#include "../infint.c"

// valid test strings
char* test_valid_bin_string      = "0101 1010";
char* test_valid_oct_string      = "777 777 777";
char* test_valid_dec_string      = "1 000 000 000";
char* test_valid_hex_string      = "DEAD BEEF";

//invalid test strings
char* test_invalid_bin_string    = "1212 1212";
char* test_invalid_oct_string    = "888 888 888";
char* test_invalid_dec_string    = "AAA BBB CCC";
char* test_invalid_hex_string    = "GGG GGG GGG";

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0;

  printf("-->string null arguments\n"); tests_counter++;
  if (infint_validate(NULL, infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN, 
                            infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1) 
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("-->null alphabet pointer\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string, 
                      NULL,                INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("-->null alphabet length\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, 0,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }
  
  printf("-->valid bin string reaction\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == 1)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("-->null skip pointer\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      NULL,                INFINT_SKIP_SYMBOLS_LEN) == 0)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("-->zero skip alphabet length\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, 0                      ) == 0)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  if (tests_counter > passed_counter) { result = -1; }
  return result; }
