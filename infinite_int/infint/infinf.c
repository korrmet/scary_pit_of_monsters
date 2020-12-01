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

int   infint_set    (void* _this, char* str  )
{ if (_this == NULL) { perr("NULL _this arg\n"); return -1; }
  if (str   == NULL) { perr("NULL str arg\n");   return -1; }

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
