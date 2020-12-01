#ifndef INFINT_H
#define INFINT_H

/** \brief settings for infinite int */
typedef struct //infint_settings_t
{ void* (*alloc  )(size_t s          ); ///< define memory allocator function
  void* (*realloc)(void*  p, size_t s); ///< define memory reallocation function
  void  (*free   )(void*  p          ); ///< define memory free_function
} infint_settings_t;

/** \brief public fields of class infinite int */
typedef struct //infint_t
{ /** \brief   setter
    * \details get string with a number as input and modify internal memory.
    *          it may allocate or reallocate memory as needed.
    *          define settings before using this method
    * \param   str string of symbols. May contain symbols [0-9] and minus if
    *              needed
    * \return  error
    * \retval  0   all ok
    * \retval  -1  error */
  int               (*set)    (void* _this, char* str  );
  /** \brief   getter
   *  \details return pointer to string of symbols which contain representation
   *           of internal storage in human readable form as described in flags.
   *           it may allocate or reallocate memory as needed.
   *           define settings before using this method.
   *  \param   flags string of symbols which specify output format
   *  \return  pointer to string of symdols with representation of contained 
   *           value.
   *           \note this pointer or string may be changed every call of getter,
   *                 so you must protect procedure of operating value. But in
   *                 most cases you will just print it, i'm don't think you
   *                 will have problems cause multiple access to getter
   *  \retval  NULL  execution error
   *  \retval  !NULL pointer to string of symbols */
  char*             (*get)    (void* _this, char* flags);
  /** \brief   destructor
   *  \details free all used memory. define settings bedore using this method.
   *  \param   _this pointer to current object
   *  \return  error
   *  \retval  0  all ok
   *  \retval  -1 error */
  int               (*destroy)(void* _this             );
  /** \brief   settings of this number
   *  \setails in most contains settings which could be defined as global, but
   *           IMHO it is a bad idea because i don't wanna chain your hands
   *           with global variables of define macro because it can break your
   *           existing code */
  infint_settings_t settings;
} infint_t;

/** \brief private fields of class infinite int */
typedef struct //infint_private_t
{ void* mem;  ///< pointer to memory which contains int data
  int   size; /**< size of memory in bytes
                   \note this is reason why at present day i laid about infinity
                         of this int. actually it is almost infinity, but i can
                         fix it later. it's just concept isn't it? */
  void* str;  ///< string of symbols which represent contained value
  void* flg;  ///< string of flags last requested
} infint_private_t;

typedef struct //infint_class_t
{ infint_t         _public;
  infint_private_t _private;
} infint_class_t;

int   infint_set    (void* _this, char* str  ); ///< setter     body
char* infint_get    (void* _this, char* flags); ///< getter     body
int   infint_destroy(void* _this             ); ///< destructor body

#define infint__ctor { ._public.set = infint_set, \
                       ._public.get = infint_get }

#define NEW(type, name)                        \
  type##_class_t name##__class = type##__ctor; \
  type##_t* name = (type##_t*)&name##__class;

/** \defgroup infinite int toolkit
 *  \details  contains functions with mathematical operations of infinite 
 *            numbers or another stuff */
///\{

/** \brief   add one infinite int to another
 *  \details result is stored inside 'a' number (see description of params)
 *  \param   a  number in sequence "a+b"
 *  \param   b  number in sequence "a+b"
 *  \return  error
 *  \retval  0  all ok
 *  \retval  -1 error */
int       infint_add (infint_t* a, infint_t* b);

/** \brief   add one infinite int to another
 *  \details creates a new variable and store result to it without modifying
 *           input numbers.
 *           \note don't ignore result of this function cause it can be source
 *                 of memory leak.
 *  \param   a     number in sequence "a+b=c"
 *  \param   b     number in sequence "a+b=c"
 *  \return  pointer to number 'c' in sequence "a+b=c"
 *  \retval  NULL  execution error
 *  \retval  !NULL pointer to result */
infint_t* infint_addc(infint_t* a, infint_t* b);

/** \brief   substract one intfinite int from another
 *  \details result stored inside 'a' number (see description of params)
 *  \param   a  number in sequence "a-b"
 *  \param   b  number in sequence "a-b"
 *  \return  error
 *  \retval  0  all ok
 *  \retval  -1 error */
int       infint_sub (infint_t* a, infint_t* b);

/** \brief   substract one infinite int from another
 *  \details crates a new variable and store result to it without modifying
 *           input numbers.
 *           \note don't ignore result of this function cause it can be source
 *                 of memory leak.
 *  \param   a     number in sequence "a-b=c"
 *  \param   b     number in sequence "a-b=c"
 *  \return  pointer to number 'c' in sequence "a-b=c"
 *  \retval  NULL  execution error
 *  \retval  !NULL pointer to result */
infint_t* infint_subc(infint_t* a, infint_t* b);

/** \brief   multiply two infinite int
 *  \details result stored inside 'a' number (see description of params)
 *  \param   a  number in sequence "a*b"
 *  \param   b  number in sequence "a*b"
 *  \return  error
 *  \retval  0  all ok
 *  \retval  -1 error */
int       infint_mul (infint_t* a, infint_t* b);

/** \brief   multiply two infinite int
 *  \details crates a new variable and store result to it without modifying
 *           input numbers.
 *           \note don't ignore result of this function cause it can be source
 *                 of memory leak.
 *  \param   a     number in sequence "a*b=c"
 *  \param   b     number in sequence "a*b=c"
 *  \return  pointer to number 'c' in sequence "a*b=c"
 *  \retval  NULL  execution error
 *  \retval  !NULL pointer to result */
infint_t* infint_mulc(infint_t* a, infint_t* b);

/** \brief   divide one infinite int by another
 *  \details result stored inside 'a' number (see description of params)
 *  \param   a  number in sequence "a/b"
 *  \param   b  number in sequence "a/b"
 *  \return  error
 *  \retval  0  all ok
 *  \retval  -1 error */
int       infint_div (infint_t* a, infint_t* b);

/** \brief   divide one infinite int by another
 *  \details crates a new variable and store result to it without modifying
 *           input numbers.
 *           \note don't ignore result of this function cause it can be source
 *                 of memory leak.
 *  \param   a     number in sequence "a/b=c"
 *  \param   b     number in sequence "a/b=c"
 *  \return  pointer to number 'c' in sequence "a/b=c"
 *  \retval  NULL  execution error
 *  \retval  !NULL pointer to result */
infint_t* infint_divc(infint_t* a, infint_t* b);

/** \brief   copy one infinite int to another
 *  \param   a  number in sequence "a=b"
 *  \param   b  number in sequence "a=b"
 *  \return  error
 *  \retval  0  all ok
 *  \retval  -1 error */
int       infint_cpy (infint_t* a, infint_t* b);

/** \brief   clone infinite int variable
 *  \details creates a new variable and copy all fields of class and memory
 *           in created variable
 *           \note don't ignore result of this function cause it can be source
 *                 of memory leak.
 *  \param   a     infinite int number
 *  \return  pointer to cloned number
 *  \retval  NULL  execution error
 *  \retval  !NULL pointer to result */
infint_t* infint_cln (infint_t* a             );

///\}

/** \defgroup debugging settings
 *  \details  contains commented macro defines wich activate some sorts of debug
 *            messages. Best way to activate some output is put -D flags to
 *            compiler, but you can just uncomment what you interested for. if 
 *            needed place include before INFINT_PRINTF definition but a better
 *            way tell your compiler to include needed file. E.g. gcc have flag
 *            "-include <filename>" */
///\{

//#define INFINT_PRINTF      ///< set printf realization
//#define INFINT_PERR_ENABLE ///< activate ERRors output
//#define INFINT_PWRN_ENABLE ///< activate WaRNing output
//#define INFINT_PMSS_ENABLE ///< activate MeSSages output
//#define INFINT_PDBG_ENABLE ///< activate DeBuG-specific output

///\}

#endif//INFINT_H
