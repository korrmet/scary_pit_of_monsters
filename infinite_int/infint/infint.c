#include <string.h>
#include <stdint.h>
#include "infint.h"

#ifndef INFINT_WORDLEN
#define INFINT_WORDLEN 1
#endif

/** \addtogroup debugging and logging environment macroses */
///\{
#if (defined(INFINT_PERR_ENABLE) && defined(INFINT_PRINTF))
#define perr(str, ...) INFINT_PRINTF("[infint][%s][err]", __FUNCTION__); \
                       INFINT_PRINTF(str, ##__VA_ARGS__)
#else
#define perr(str, ...)
#endif

#if (defined(INFINT_PWRN_ENABLE) && defined(INFINT_PRINTF))
#define pwrn(str, ...) INFINT_PRINTF("[infint][%s][wrn]", __FUNCTION__); \
                       INFINT_PRINTF(str, ##__VA_ARGS__)
#else
#define pwrn(str, ...)
#endif

#if (defined(INFINT_PMSS_ENABLE) && defined(INFINT_PRINTF))
#define pmss(str, ...) INFINT_PRINTF("[infint]");        \
                       INFINT_PRINTF(str, ##__VA_ARGS__)
#else
#define pmss(str, ...)
#endif

#if (defined(INFINT_PDBG_ENABLE) && defined(INFINT_PRINTF))
#define pdbg(str, ...) INFINT_PRINTF("[infint][dbg]");   \
                       INFINT_PRINTF(str, ##__VA_ARGS__)
#else
#define pdbg(str, ...)
#endif
///\}

#define INFINT_ESCAPE_SYMBOL '\\'

/** \brief   parse string with binary number
 *  \details string will be parset till zero-terminator. spaces will be ignored
 *  \param   _this pointer to object of class which number will be stored
 *  \param   str   pointer to source string
 *  \return  error
 *  \retval  0     all ok
 *  \retval  -1    error occured */
int infint_parse_bin(void* _this, char* str);

/** \brief   parse string with octal number
 *  \details string will be parset till zero-terminator. spaces will be ignored
 *  \param   _this pointer to object of class which number will be stored
 *  \param   str   pointer to source string
 *  \return  error
 *  \retval  0     all ok
 *  \retval  -1    error occured */
int infint_parse_oct(void* _this, char* str);

/** \brief   parse string with decimal number
 *  \details string will be parset till zero-terminator. spaces will be ignored
 *  \param   _this pointer to object of class which number will be stored
 *  \param   str   pointer to source string
 *  \return  error
 *  \retval  0     all ok
 *  \retval  -1    error occured */
int infint_parse_dec(void* _this, char* str);

/** \brief   parse string with hexadecimal number
 *  \details string will be parset till zero-terminator. spaces will be ignored
 *  \param   _this pointer to object of class which number will be stored
 *  \param   str   pointer to source string
 *  \return  error
 *  \retval  0     all ok
 *  \retval  -1    error occured */
int infint_parse_hex(void* _this, char* str);

/** \brief   pool of parsers
 *  \details just replace switch-case to better look */
int (*infint_parsers[4])(void* _this, char* str) = { infint_parse_bin,
                                                     infint_parse_oct,
                                                     infint_parse_dec,
                                                     infint_parse_hex };

int   infint_set    (void* _this, char* str  )
{ if (_this == NULL) { perr("NULL _this arg\n"); return -1; }
  if (str   == NULL) { perr("NULL str arg\n");   return -1; }
  
  int minus = 0; if (*str == '-') { minus = 1; str++; }

  enum { BIN = 0, OCT = 1, DEC = 2, HEX = 3 } num_type;
  switch (*str)
  { case '0': { str++; switch(*str)
                       { case 'x': num_type = HEX; str++; break;
                         case '0':
                         case '1':
                         case '2':
                         case '3':
                         case '4':
                         case '5':
                         case '6':
                         case '7':
                         case '8':
                         case '9': num_type = OCT;        break;
                         case 'b': num_type = BIN; str++; break;
                         default: 
                         { perr("(%08x) unexpected type qualifier %d\n", 
                                _this, *str); 
                           return -1; } } 
              } break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': num_type = DEC; break;
    default: perr("(%08x) unexpected symbol %c\n", _this, *str); return -1; }
  
  if (infint_parsers[num_type](_this, str) == -1) 
  { perr("(%08x) can't parse number \"%s\"\n", _this, str); return -1; }

  return 0; }

char* infint_get    (void* _this, char* flags)
{ if (_this == NULL) { perr("NULL _this arg\n"); return NULL; }
  
  return 0; }

int   infint_destroy(void* _this             )
{ if (_this == NULL) { perr("NULL _this arg\n"); return -1; }

  return 0; }

int       infint_add (infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return -1; }
  if (b == NULL) { perr("NULL b arg\n"); return -1; }

  return 0; }

infint_t* infint_addc(infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return NULL; }
  if (b == NULL) { perr("NULL b arg\n"); return NULL; }
  
  infint_t* c = infint_cln(a); 
  if (c == NULL) { perr("can't create c\n"); return NULL; }
  if (infint_add(c, b) == -1) 
  { if (infint_destroy(c) == -1) { perr("can't destroy c\n"); } 
    perr("can't add b to c\n"); return NULL; }

  return c; }

int       infint_sub (infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return -1; }
  if (b == NULL) { perr("NULL b arg\n"); return -1; }

  return 0; }

infint_t* infint_subc(infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return NULL; }
  if (b == NULL) { perr("NULL b arg\n"); return NULL; }

  infint_t* c = infint_cln(a); 
  if (c == NULL) { perr("can't create c\n"); return NULL; }
  if (infint_sub(c, b) == -1) 
  { if (infint_destroy(c) == -1) { perr("can't destroy c\n"); } 
    perr("can't substract b from c\n"); return NULL; }

  return c; }

int       infint_mul (infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return -1; }
  if (b == NULL) { perr("NULL b arg\n"); return -1; }

  return 0; }

infint_t* infint_mulc(infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return NULL; }
  if (b == NULL) { perr("NULL b arg\n"); return NULL; }

  infint_t* c = infint_cln(a); 
  if (c == NULL) { perr("can't create c\n"); return NULL; }
  if (infint_mul(c, b) == -1) 
  { if (infint_destroy(c) == -1) { perr("can't destroy c\n"); } 
    perr("can't multiply a and c\n"); return NULL; }

  return c; }

int       infint_div (infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return -1; }
  if (b == NULL) { perr("NULL b arg\n"); return -1; }

  return 0; }

infint_t* infint_divc(infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return NULL; }
  if (b == NULL) { perr("NULL b arg\n"); return NULL; }

  infint_t* c = infint_cln(a); 
  if (c == NULL) { perr("can't create c\n"); return NULL; }
  if (infint_div(c, b) == -1) 
  { if (infint_destroy(c) == -1) { perr("can't destroy c\n"); } 
    perr("can't divide c by b\n"); return NULL; }

  return c; }

int       infint_cpy (infint_t* a, infint_t* b)
{ if (a == NULL) { perr("NULL a arg\n"); return -1; }
  if (b == NULL) { perr("NULL b arg\n"); return -1; }

  return 0; }

infint_t* infint_cln (infint_t* a             )
{ if (a == NULL) { perr("NULL a arg\n"); return NULL; }
  
  infint_t* clone = NULL;

  return clone;}

/** \brief   check what symbol in requested alphabet
 *  \details just checking every alphabet symbol in loop
 *  \param   sym      symbol to check
 *  \param   alphabet pointer to alphabet array
 *  \param   length   length of alphabet array
 *  \return  result or error
 *  \retval  -1       error
 *  \retval  0        symbol is not in alphabet
 *  \retval  1        symbol is in alphabet */
int infint_is_in_alphabet(char sym, char* alphabet, int length)
{ if (alphabet == NULL) { perr("NULL aplhabet argument\n"); return -1; }
  if (length   == 0   ) { perr("empty alphabet\n");         return -1; }
 
  for (int i = 0; i < length; i++) { if (sym == alphabet[i]) { return 1; } }

  return 0; }

#define INFINT_SKIP_SYMBOLS_LEN 2
char infint_skip_symbols[INFINT_SKIP_SYMBOLS_LEN]
= { ' ', '\t' };

#define INFINT_SPECIAL_SYMBOLS_LEN 2
char infint_special_symbols[INFINT_SPECIAL_SYMBOLS_LEN]
= { 0, INFINT_ESCAPE_SYMBOL };

#define INFINT_BIN_ALPHABET_LEN 2
char infint_bin_alphabet[INFINT_BIN_ALPHABET_LEN] 
= { '0', '1' };

/** \brief   validates number in specified format
 *  \details scan string and check what int contain only valid symbols
 *  \param   str          source string
 *  \param   alphabet     array of symbols of alphabet of expression
 *  \param   alphabet_len length of this array
 *  \param   skip         array of symbols which will ignore while parsing
 *  \param   skip_len     length of this array
 *  \return  result of validation or error
 *  \retval  -1           error
 *  \retval  0            string is invalid
 *  \retval  1            string is valid */
int infint_validate(char* str, char* alphabet, int alphabet_len, 
                               char* skip,     int skip_len)
{ if (str          == NULL) { perr("NULL arg str\n");      return -1; }
  if (alphabet     == NULL) { perr("NULL arg alphabet\n"); return -1; }
  if (alphabet_len == 0   ) { perr("empty alphabet\n");    return -1; }
 
  if ((skip == NULL) && (skip_len > 0)) 
  { pwrn("skip-symbol alphabet pointer is empty but it's length isn't 0\n"); 
    pwrn("maybe you forgot to tell which skip-symbols are needed?\n"); }
  if ((skip != NULL) && (skip_len == 0))
  { pwrn("skip-symbol alphabet pointer is not empty but it's length is 0\n");
    pwrn("if you don't want to skip symbols just set skip arg to null\n"); }
  while (*str != 0)
  { if ((skip != NULL) && (skip_len > 0))
    { switch (infint_is_in_alphabet(*str, skip, skip_len))
      { case  0: break;
        case  1: str++; break;
        case -1: perr("can't check symbol \'%c\'\n", *str); return -1; 
        default: perr("unexpected validator state\n");      return -1; } }
    switch (infint_is_in_alphabet(*str, alphabet, alphabet_len))
    { case  0: return 0;
      case  1: break;
      case -1: perr("can't check symbol \'%c\'\n", *str); return -1;
      default: perr("unexpected validator state\n");      return -1; } 
    str++; }
  return 1; }

int infint_parse_bin(void* _this, char* str)
{ if (_this == NULL) { perr("NULL _this arg\n"); return -1; }
  if (str   == NULL) { perr("NULL str arg\n");   return -1; }

  infint_validate(str, infint_bin_alphabet, INFINT_BIN_ALPHABET_LEN,
                       infint_skip_symbols, INFINT_SKIP_SYMBOLS_LEN);

  uint8_t* mem = (uint8_t*)((infint_class_t*)_this)->_private.mem;
  int byte_ctr = 0;
  while (*str != 0)
  { if (infint_is_in_alphabet(*str, 
                              infint_skip_symbols, 
                              INFINT_SKIP_SYMBOLS_LEN) == 1)
    { str++; continue; }
    switch (*str)
    { case '0': *mem &= ~(1 << (7 - byte_ctr)); break;
      case '1': *mem |=   1 << (7 - byte_ctr);  break;
      default: perr("unexpected symbol \'%c\'\n", *str); return -1; }
    byte_ctr++; if (byte_ctr >= 8) { byte_ctr = 0; mem++; } str++; }

  //changing byte order
  uint8_t* mem_start = (uint8_t*)((infint_class_t*)_this)->_private.mem;
  uint8_t* mem_end   = mem - 1; //previous is real last member
  while (mem_start < mem_end)
  { uint8_t tmp; tmp = *mem_start; *mem_start = *mem_end; *mem_end = tmp;
    mem_start++; mem_end--; }

  //add escape-symbols if it needed in result
  uint8_t* current = (uint8_t*)((infint_class_t*)_this)->_private.mem;
  mem_end   = mem;
  while (current < mem_end)
  { switch (infint_is_in_alphabet(*current,
                                  infint_special_symbols,
                                  INFINT_SPECIAL_SYMBOLS_LEN))
    { case 0: break;
      case 1: /* TODO: think about how to insert symbol in memory */ break;
      default: perr("can't parse symbol during escape-symbols adding\n"); 
               return -1; } 
    current++; }

  return 0; }

#define INFINT_OCT_ALPHABET_LEN 8
char infint_oct_alphabet[INFINT_OCT_ALPHABET_LEN] = 
{ '0', '1', '2', '3', '4'};
  
int infint_parse_oct(void* _this, char* str)
{ return 0; }

#define INFINT_DEC_ALPHABET_LEN 10
char infint_dec_alphabet[INFINT_DEC_ALPHABET_LEN] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int infint_parse_dec(void* _this, char* str)
{ 
  return 0; }

#define INFINT_HEX_ALPHABET_LEN 22
char infint_hex_alphabet[INFINT_HEX_ALPHABET_LEN] = 
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
  'A', 'B', 'C', 'D', 'E', 'F',
  'a', 'b', 'c', 'd', 'e', 'f' };

int infint_parse_hex(void* _this, char* str)
{ return 0; }
