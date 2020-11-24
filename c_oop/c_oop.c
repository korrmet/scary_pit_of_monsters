#include <stddef.h>
#include "c_oop.h"

#define THIS ((counter_class_t*)_this)

void counter_operate(void* _this)
{ if (_this == NULL) { return; }
  THIS->_private.count++;
  if (THIS->_private.count >= THIS->_public.delimeter)
  { THIS->_private.count = 0;
    THIS->_public.state = (THIS->_public.state) ? 0 : 1; } }

#undef THIS
#define THIS ((predef_counter_class_t*)_this)

void predef_counter_operate(void* _this)
{ if (_this == NULL) { return; }
  if (THIS->_public.pre_load) { THIS->_public.pre_load--; return; }
  THIS->_private.count++;
  if (THIS->_private.count >= THIS->_public.cnt.delimeter)
  { THIS->_private.count = 0;
    THIS->_public.cnt.state = (THIS->_public.cnt.state) ? 0 : 1; } }
