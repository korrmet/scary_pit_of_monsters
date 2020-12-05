#include <stdio.h>
#define INFINT_PRINTF printf
#include "../infint.c"

// valid test strings
char* test_valid_bin_string      = "0b 0101 1010";
char* test_valid_oct_string      = "0 777 777 777";
char* test_valid_dec_string      = "1 000 000 000";
char* test_valid_hex_string      = "0x DEAD BEEF";

//invalid test strings
char* test_invalid_bin_string    = "0b 1212 1212";
char* test_invalid_oct_string    = "0 888 888 888";
char* test_invalid_dec_string    = "1 AAA BBB CCC";
char* test_invalid_hex_string    = "0x GGG GGG GGG";
char* test_invalid_format_string = "0j 123 456 789";
char* test_invalid_symbol_string = "0b 0101 \n 0101";

int main(void)
{ int result = 0; int tests_counter = 0; int passed_counter = 0;

  printf("string null arguments\n"); tests_counter++;
  if (infint_validate(NULL, infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN, 
                            infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1) 
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("null alphabet pointer\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string, 
                      NULL,                INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("null alphabet length\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }
  
  printf("null skip pointer\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      NULL,                INFINT_SKIP_SYMBOLS_LEN) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("zero skip alphabet length\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, 0                      ) == -1)
  { passed_counter++; }
  else { printf("fail\n"); }

  printf("valid bin string reaction\n"); tests_counter++;
  if (infint_validate(test_valid_bin_string,
                      infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                      infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN) == 1)
  { passed_counter++; }
  else { printf("fail\n"); }


  printf("stat: %d/%d passed\n", passed_counter, tests_counter); 
  return result; }

