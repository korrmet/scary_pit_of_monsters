#ifndef INFINT_H
#define INFINT_H

/** \brief position in data stream */
typedef enum //infint_mem_pos_t
{ INFINT_MEM_POS__START = 0, ///< start of data stream
  INFINT_MEM_POS__CURRENT,   ///< current position in data stream
  INFINT_MEM_POS__END        ///< end of data stream
} infint_mem_pos_t;

/** \brief behavour mode of write data stream operation */
typedef enum //infint_wr_mode_t
{ INFINT_WR_MODE__INSERT = 0, ///< insertion
  INFINT_WR_MODE__REPLACE     ///< replacement
} infint_wr_mode_t;

typedef struct //infint_mem_settings_t
{ /** \brief   read n bytes from memory by current position
    * \details mechanism must be similar to file stream
    * \param   ptr  pointer to data buffer
    * \param   len  size in bytes which volume of data must be readen
    * \param   id   identifier of data stream
    * \return  error or bytes readen 
    * \retval  -1   error occured due execution
    * \retval  >= 0 num of readen bytes */
  int (*rd)(void* ptr, unsigned int len, unsigned int id);
  /** \breif   write n bytes to memory from current position
   *  \details memory must be automatically extended if you write at the end in 
   *           any mode, or in any position in inset mode 
   *  \param   ptr  pointer to data buffer
   *  \param   len  size in bytes which volume of data must be written
   *  \param   mode write mode
   *  \param   id   identifier of data stream
   *  \return  error or bytes written
   *  \retval  -1   error occured due execution
   *  \retval  >= 0 num of written bytes */
  int (*wr)(void* ptr, unsigned int len, int mode, unsigned int id);
  /** \brief   remove block of memory from data stream
   *  \details removal zone starts from current position to n bytes towards
   *  \param   len size in bytes which volume must be removed
   *  \param   id  identifier of data stream
   *  \return  error or bytes removed
   *  \retval  -1   error occured due execution
   *  \retval  >= 0 num of removed bytes */
  int (*rm)(int len, int id);
  /** \brief   change position in data stream
   *  \details set position in stream by settings in arguments. you can change
   *           position in num of bytes towards or backwards of current
   *           position, start of data stream, end of data stream
   *  \param   pos   position marker
   *  \param   shift shift in bytes (may be 0 or negative number)
   *  \param   id    identifier of data stream
   *  \return  error
   *  \retval  -1    error occured due execution
   *  \retval  0     success */
  int (*pos)(int pos, int shift, unsigned int id);
  /** \brief creates new data stream
   *  \return identifier or error
   *  \retval 0  error occured due execution or can't get memory
   *  \retval >0 valid identifier of data stream */
  unsigned int (*crt)(void);
  /** \brief  deletes data stream
   *  \param  id identifier
   *  \return error
   *  \retval -1 error occured due execution
   *  \retval 0  success */
  int (*del)(int id);
} infint_mem_settings_t;

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
  /** \brief   memory settings of this number
   *  \details you must manually define this structure according to
   *           specification below. This interface is architecture independent
   *           so you can port it on any machine and any OS which your compiler
   *           applies */
  infint_mem_settings_t settings;
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
//#define INFINT_WORDLEN     ///< length of word in bits (default 1 bit)

///\}

#endif//INFINT_H
