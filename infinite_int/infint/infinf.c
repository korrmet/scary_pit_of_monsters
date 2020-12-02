#include <string.h>
#include "infint.h"

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

  infint_t c = infint_cln(a); 
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

  infint_t c = infint_cln(a); 
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

  infint_t c = infint_cln(a); 
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

int infint_parse_bin(void* _this, char* str)
{ return 0; }

int infint_parse_oct(void* _this, char* str)
{ return 0; }

int infint_parse_dec(void* _this, char* str)
{ return 0; }

int infint_parse_hex(void* _this, char* str)
{ return 0; }
