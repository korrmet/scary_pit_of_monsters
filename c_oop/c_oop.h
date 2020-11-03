#ifndef C_OOP_H
#define C_OOP_H

typedef struct //counter_t
{ int  state;
  int  delimeter;
  void (*operate)(void* _this);
} counter_t;
typedef struct //counter_private_t
{ int count;
} counter_private_t;
typedef struct //counter_class_t
{ counter_t         _public;
  counter_private_t _private;
} counter_class_t;
void counter_operate(void* _this);
#define counter__ctor { ._public.operate = counter_operate }

typedef struct //predef_counter_t
{ counter_t cnt;
  int       pre_load;
} predef_counter_t;
typedef struct //predef_counter_class_t
{ predef_counter_t  _public;
  counter_private_t _private; 
} predef_counter_class_t;
void predef_counter_operate(void* _this);
#define predef_counter__ctor { ._public.cnt.operate = predef_counter_operate }

#define NEW(type, name) \
type##_class_t name##__class = type##__ctor; \
type##_t* name = (type##_t*)&name##__class;

#endif
