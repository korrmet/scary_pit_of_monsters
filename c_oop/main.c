#include <stdio.h>
#include "c_oop.h"

NEW(counter, ctr1);
NEW(predef_counter, ctr2);
NEW(counter, ctr3);

counter_t* ctr_pool[] = { (counter_t*)&ctr1__class,
                          (counter_t*)&ctr2__class, 
                          (counter_t*)&ctr3__class };

int main(void)
{ ctr1->delimeter = 4;
  ctr2->pre_load = 3; ctr2->cnt.delimeter = 4;
  ctr3->delimeter = 2;
  for (int i = 0; i < 16; i++)
  { printf("%2d: ", i);
    for (int j = 0; j < 3; j++)
    { ctr_pool[j]->operate(ctr_pool[j]); printf("%s", ctr_pool[j]->state); }
    printf("\n");
  }
}
