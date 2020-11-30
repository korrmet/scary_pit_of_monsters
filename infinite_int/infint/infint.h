#ifndef INFINT_H
#define INFINT_H

typedef struct //infint_t
{ int   (*set)(char* str  );
  char* (*get)(char* flags);
} infint_t;
typedef struct //infint_private_t
{
} infint_private_t;
typedef struct //infint_class_t
{ infint_t         _public;
  infint_private_t _private;
} infint_class_t;

int   infint_set(char* str  );
char* infint_get(char* flags);
#define infint__ctor { ._public.set = infint_set, \
                       ._public.get = infint_get }

#define NEW(type, name)                        \
  type##_class_t name##__class = type##__ctor; \
  type##_t* name = (type##_t*)&name##__class;

#endif//INFINT_H
