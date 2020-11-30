# scary\_pit\_of\_monsters

![kenny](https://github.com/korrmet/scary_pit_of_monsters/raw/main/kenny_cheesing.gif)

This is a place where creatures of your nightmares will alive.  Ugly but  pretty
useful templates, ideas, methods will be dropped in this pit for eternal  battle
on bloody sands arena. Make Radar Rider loud...

Most of these examples are written in c because  i  have  not  practice  at  any
another programming language. 

## my coding style

![bloody\_eyes](https://github.com/korrmet/scary_pit_of_monsters/raw/main/bloody_eyes.jpg)

Let me explain if you still see this text.  Codestyle  must  help  you  in  your
everyday work and any help you can measure.  Sometimes codestyle  prevents  some
actions like a linux kernel codestyle.  Sometimes coding style is famous because
it's ugly like a K&R. But i'm don't care about how it beautiful. So what is and
why my coding style exists?

### what is

One day i saw finnish guy Bisquit on youtube.  He demonstrates his ideas as live
programming.  I checked what his format is wery compact so he can display it  in
low quality video mode.  Otherwise i'm tired on my job  because  people  do  not
properly read another code and they take silly errors.  Maybe  it  cruel  but  i
decide to force really read what i write and fix  most  of  errors  before  they
occur.

#### formatting

* I don't use tab. 
* Ident = 2 spaces. 
* Width = 80 chars, but this rule can be broken in rare situations.  In years of
  coding i still never broke it.
* Several instructions in one line allowed and welcomed
* Multiline block of code  rounded  braces  starts  in  new  line  after  parent
  construction.
* Instructions inside braces starts in same line as brace typed
* Closing brace puts in same line as last instruction of block
* Braces has interval = space. This rule can be broken in rare situations
* Pointers declares as: `void* foo = &bar;`
* All executable code is divided into paragraphs separated by an empty line from
  each other. The paragraph is one complete simple though that cannot be divided
  into nonterminal parts. This rule applies to formatting indirectly. Part of it
  is related to the grouping provisions and will be duplicated in that section.
* Try to format your code to vertical blocs if you can.

Example:
```
#include <stdio.h>

void swap(int* a, int* b) { int tmp = *a; *a = *b; *b = tmp; }

char* strings[] = { "First string",  "Second string", "Third string",
                    "Fourth string", "Fifth string",  "Sixth string",
                    "7-th string",   "8-th string",   "9-th string"   };

int main (void)
{ for (int i = 0; i < 10; i++) { printf("%d ", i);  }
  
  int a = 5; int b = 6;
  if (a > b) 
  { while (a > b) { a--; b--; printf("a: %d, b: %d\n", a, b); }
    printf("completed!\n"); }
  if (a/b < 10) { swap(&a, &b); printf("a/b: %d\n", a/b); }

  printf("finally: a: %d, b: %d\n", a, b); }
```

#### commenting

* Commenting in doxygen format is allowed and welcomed
* Always comment first declaration of functions or macroses. Try explain what it
  doing in brief section, how it works in details section, and comment arguments
* Sometimes place comment inside body of function between code lines
* Comment in same line of code of function only if it REALLY need.  This must be
  rare situation. This comment must be as short as possible, maybe only one word
* Comment structure  members  or  enumeration  in  doxygen  format.   In  normal
  situation comment it using "///<" construction. If your comment don't fetch in
  line use standard multiline doxygen comment
* If you want to create link to another code, place keyword in square  brackets.
  This keywork is a name of mark which can be tagged in comment using ":".   You
  can use it as tag system.  If you see this pattern in code - just grep  it  to
  see another.
* The good comment is good name of variable or function.  The  best  comment  is
  printf, which defined by preprocessor.

```
#define FOO 2 ///foo is equal 2 :foo:

...
//if [foo] defined as non-null ...
if (FOO) { ... }
```

### why

Today most of us trying to save space for better working.   We  use  60  and  40
percent keyboards, tiling window managers,  multiple  workspaces,  compact  text
editors and IDE's, we buy multiple wide displays.  But for what?   To  see  much
empty space and wallpapers. So first reason is more compact code. Don't hurry to
buy big monitor and save your money.

Just compare as example gnu style code:

```
 1 int foo
 2 (int bar)
 3 {
 4     //checking for inompitable arg bar
 5     if (bar < 0)
 6     {
 7         return -1;
 8     }
 9 
10     for (int i = 0; i < 10; i++)
11     {
12         if (bar % 3 == 1)
13         {
14             bar++;
15         }
16     }
17
18     return bar;
19 }
```

And that:

```
int foo (int bar)
{ if (bar < 0) { return -1; } //checking for incompitable arg
  for (int i = 0; i < 10; i++) { if (bar & 3 == 1) { bar++; } }
  return bar; }
```

Did you see that?  Same code in 4 strings instead of 19.   Do  you  really  need
second or third, of fourth ....  n-th monitor?  How fast you scroll it, how much
tabs and splits you will open using it?

Codestyle also need to help you in work with code.  Standartisized format  helps
to see code written by another people.  But it is not true at all.   Your  brain
loves similar things as you doing. So common formatted code has less mistakes in
our minds becaude we feel like this code we can write ourselves. That's so cute,
but what happens if we see another code formatting, e.g.  Linux kernel code.  Do
you fell headache? But this code is not bad, but you feel what it bad. Feelings
are not good helper in programming.  At first my code style has elements of  all
code styles i have seen.  You can rapidly switch to it if you want and switch to
another. At second, my code style turns you to see code instead formatting. This
is a wery useful ability.

Next, you can code everywhere in any device.  Sometimes all of us worked without
table with laptop on knees.  It's most uncomfortable thing.  My coding style has
very simple formatting that decreases keyboard using.   It  helps  you  to  feel
little more comfort in hard situations.

Also my coding style provide features what i never see  before  which  helps  to
create review plan and sometimes  automate  your  reviews.   This  can  increase
speed of code checking and delivery it to product.  Maybe it will only tool  for
code validation you available.

### how

Main question is how to read this code.  It's simple: from up to bottom and left
to right. Simply, is not it? 

### side effects

I use this codestyle approximately two years. I never lose brackets these years,
other people forced to read my code properly, so they start to really understand
it, i'm never feel claustrophobia when i'm using laptop, code writing is more
comfortable.

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

## what if you need store 1 yotta in variable...

We know what Python have infinite int and it can contain any value which can  be
placed at ROM.  It's cool feature,  but  it's  unable  in  C.   However  several
realizations is exists at present day, but what can  be  better  than  invetntig
bikes? Let's do it.

Let's think how it can be looks.  Let we have any type of  container  what  will
represent our infinite int.  How we set it to so big number, which  bigger  than
64 bits can contain? We can't just type something as:

```
infint_t foo = 1000000000000000000000;
```
We just catch error what constant's value is too much.  I know  only  one  type,
which C can store with any length.  This is array of chars or string.  So we can
make some sort of this:

```
#include <stdio.h>

int main(void) { printf("%s\n", "1000000000000000000000"); }
```

Keep attention how we can manipulate  strings.   It's  look  like  what  we  ask
compiler to show us number 1 yotta. And we get it. So i think, what our infinite
int must interact using strings.

Strings we can use as argument of some function.   But  how  to  chain  together
between function and data which it will operaty?  We need help of OOP.   I  told
earlier how to take it on C.  We need encapsulate storage and functions get  and
set inside class of our infinite int. This will be looks like some as:

```
...
NEW(infint, iint);
...
iint->set("1000000000000000000000");
printf("%s\n", iint->get());
```

Decide format of flags bit later because we have a trouble  about  how  we  will
store it.  We have not infinite memory and we can't  create  buffer,  which  can
contain block of data with unknown and possibly large size. Only method is using
dynamic memory.

Let we know how we will store it, but how we will operate it? We need additional
external (according to infinite int class) toolkit which provide sum,
multiplication and division. These functions can operate two infinite int
numbers so if we need to add standard int to infinite int, we have two ways:

1. create functions which operate infinite int and standard int.

2. create standart int to infinite int converter.

I like second because if we chose first we get so wide  toolkit  which  will  be
uncomfortable in using.  I think i can optimize it later, but  today  we  create
interface.

If we substract (or add positive number  to  negative)  we  can  reach  negative
result so we need signed infinite int.

And where we will store result?  Simplest way  is  allocate  memory  and  return
pointer to result.  User need to keep in mind what this memory must be free when
it will not be needed.  We wanna see working concept, so at present we can force
user of our library to control his memory himself. Maybe in real project i wrote
some tools to automate these operations.

# Epilogue

See you later when i add some more monsters in this pit and  convert  my  shitty
English to normal. May the madness be with you.
