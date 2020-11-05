# scary\_pit\_of\_monsters

![kenny](https://github.com/korrmet/scary_pit_of_monsters/raw/master/kenny_cheesing.gif)

This is a place where creatures of your nightmares will alive.  Ugly but  pretty
useful templates, ideas, methods will be dropped in this pit for eternal  battle
on bloody sands arena. Make Radar Rider loud...

Most of these examples are written in c because  i  have  not  practice  at  any
another programming language. 

## what if you need object orientied programming in c...

see c\_oop directory

Some people says what C++ is a C but with extra features which  reduce  routine.
Also C is a Turing-full language so it's can apply any algorythm which  you  can
imagine.  Let's try to find out how we can apply  object  orientied  programming
using c.

First of all let's define what we will mean when we speak about OOP.  I know two
ways: 
1) program consists of objects, objects consists of data and algorhytms, objects
interacts with another objects using messages
2) programs consists of objects, which organized in parenthesis  hierarchy,  OOP
drives encapsulation, polymorphism and inheritance.

C++ applied first statement with some conventions:
1) calling method is message which object received
2) reading or writing data is message which object received

Sounds weird, but C++ apply OOP because these conventions.  And that's why  Alan
Kay says, what it is not that OOP he developed.  But today we will discuss about
C++ OOP infrastructure.

What is class in C++?  Class is a structure with fields.  Fields  has  it's  own
access type.  All classes have constructors and destructors,  which  prepare  or
destroy data.  We can think what preprocessor directives  may  be  constructors.
If we apply this statement, next code becomes correct constructor call:

```
#define predef_counter__ctor { ._public.cnt.operate = predef_counter_operate }

...

#define NEW(type, name) \
type##_class_t name##__class = type##__ctor; \
type##_t* name = (type##_t*)&name##__class;

```

After that we can assume what manual  defining  _\_this_  pointer  (like  a  c++
_this_) so that code will be correct:

```
ctr_pool[j]->operate(ctr_pool[j]);

```
where _ctr_pool[j]_ is a pointer to object of class.

So that's we define c++ like behavour of encapsulations  data  and  code  inside
class and their objects. 

Next stop is inheritation. Next is an example how one class inherit some private
fields of parent class.

```
typedef struct //predef_counter_t
{ counter_t cnt;
  int       pre_load;
} predef_counter_t;
```

Inherited fields of parent class must be first  in  structure.   We  can  define
another struct, which will equal to parent, but it  produce  much  manual  work.
So if we have two structures with equal fields payload of several  fisrt  items,
we can get the pointer of same type and call methods  and  fields  of  diffirent
structures using pointer of same type.  Array  _ctr_pool_  displays  this  idea.
Realization   of   shadowing   private   data   founds   at   same   principles.

How about polymorphism?  You can define it by two ways.  First you can polymorph
methods  define  as  variable  arguments  function  (i  don't  use  it  in  this
demonstration, because i don't like to use  it  as  polumorphism  action).   But
another way is use special constructor:

```
#define counter__ctor { ._public.operate = counter_operate }
#define predef_counter__ctor { ._public.cnt.operate = predef_counter_operate }
```

So _predef\_counter_ class represents same interface as _counter_ class but  has
diffirent behavour of _operate_ method.

That's how you can define c++ like OOP in pure  c  (for  nerds  i'm  use  latest
standard of language and define which standard it's actually apply)  with  bonus
of invisible for user private fields which able to  be  used  outside.   (Python
still can't to this)

See you later when i add some more monsters in this pit and  convert  my  shitty
English to normal. May the madness be with you.
