# licence

I'm not sure what somebody really will use it, but don't forget in any case tell
or write what main source of this is me, Korrmet, and at present day any person
can see it at github.com/korrmet. If you ignore this term you're an asshole.


# language
i'm sooooooo sorry by my English (actually not because it's just part of practice).
Someday i fix mistakes in description (actually not because code is more important
and i dont have time for it)

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

Let's develop what is infinite int under the hood.  It is long binary which  can
be represented as string of chars (or bytes).  I think what we  no  need  invent
bicycle and just look at standard large integer types in C for example uint64:

```
                                      +----+---------+
12345678 = 0x00 00 00 00 00 BC 61 4E  |val | address |
              |  |  |  |  |  |  |  |  +----+---------+
              |  |  |  |  |  |  |  +->| 4E | ? + 0   |
              |  |  |  |  |  |  |     +----+---------+
              |  |  |  |  |  |  +---->| 61 | ? + 1   |
              |  |  |  |  |  |        +----+---------+
              |  |  |  |  |  +------->| BC | ? + 2   |
              |  |  |  |  |           +----+---------+
              |  |  |  |  +---------->| 00 | ? + 3   |
              |  |  |  |              +----+---------+
              |  |  |  +------------->| 00 | ? + 4   |
              |  |  |                 +----+---------+
              |  |  +---------------->| 00 | ? + 5   |
              |  |                    +----+---------+
              |  +------------------->| 00 | ? + 6   |
              |                       +----+---------+
              +---------------------->| 00 | ? + 7   |
                                      +----+---------+
```

At  picture  below  you  see  how  decimal  number  stores  in  memory  in   LSB
architecture. 4 bytes integer has border which marked as "? + 3", 2 bytes - "? +
1" and one byte stores in single memory unit.  Infinte int can be  written  same
but it's border will be at "? + very big number" and trailed by zero as standard
string. Let's try to represent some number as infinite int:

```
                    +----+---------+
12345 = 0x00 30 39  |val | address |
           |  |  |  +----+---------+
           |  |  +->| 39 | ? + 0   |
           |  |     +----+---------+
           |  +---->| 30 | ? + 1   |
           |        +----+---------+
           +------->| 00 | ? + 2   |
                    +----+---------+   
```

As we can see naturally we have two-bytes length number with trailing  zero.   I
think it pretty compact writing and  compitable  in  some  cases  with  standard
types.

Few words about LSB and MSB.  LSB is most useful in computations  because  carry
grows toward and also type conversion is pretty easy.  MSB is useful in  places,
where machine codes will be read by human because it's  looks  like  a  standard
notation.  If we look at net traffic using wireshark  more  comfortable  to  see
something like this:

```
00 30 39
```

because we automatically see 0x00 30 39.  But if we want to examine memory using
debugger we can see something like this:

```
39 30 00
```
and in mind we see 0x39 30 00 instead 0x00 30 39.  So  as  we  try  to  goal  in
computation problem, will be better if we will still use LSB.

What happens if we have number 5570645? Let's look at this number in hex and try
to apply our requirements:

```
                         +----+---------+
5570645 = 0x00 55 00 55  |val | address |
             |  |  |  |  +----+---------+
             |  |  |  +->| 55 | ? + 0   |
             |  |  |     +----+---------+
             |  |  +---->| 00 | ? + 1   |<-- this is not end of number but we
             |  |        +----+---------+    think what is
             |  +------->| 55 | ? + 2   |
             |           +----+---------+
             +---------->| 00 | ? + 3   |
                         +----+---------+
```

We can store length of this type in variable, but standard variables  has  their
maximum value so if we do that out infinite int will not be infinite. Better way
it use escape-sequences. Just use ASCII code of '\' (0x5C) before zero byte.

```
                         +----+---------+
5570645 = 0x00 55 00 55  |val | address |
             |  |  |  |  +----+---------+
             |  |  |  +->| 55 | ? + 0   |
             |  |  |     +----+---------+
             |  |  |     | 5C | ? + 1   |<-- escape-symbol
             |  |  |     +----+---------+
             |  |  +---->| 00 | ? + 2   |<-- read it as 0x00
             |  |        +----+---------+
             |  +------->| 55 | ? + 3   |
             |           +----+---------+
             +---------->| 00 | ? + 4   |<-- null-terminator
                         +----+---------+
```

This method increase some needed  space  but  it  apply  true  possibly-infinite
sequence.

After all we can set our number in multiple formats: binary, octal,  hexadecimal
an decimal. All of these formats has prefix (but no decimal) '0' and next may be
letter 'x' or 'b' for hexadecimal or binary.  So we will have multiple parser of
our number. Also we can have negative numbers and first character will be minus.
In my opinion best way at present is just store minus as field of structure and
sometimes when  we  try  to  add  positive  number  to  negative  just  actually
substract.  Let math tricks will be little bit later, ok?  I just wanna start it
now.

And few words about memory storage model.  We need abstraction  layer.   I  have
tried to solve problem of storing infinite values in memory many ways and i see,
what doesn't exist right methods for any case.  That's why  we  really  need  to
abstract memory model. To do that we need an interface. When i think about it i
fount some use-cases:

1. Store and operate in RAM

2. Store and operate in ROM in file

3. Store and operate in ROM in raw array

4. Operate at microcontroller with equal or less 32bit word length and
   addressing

Iterative stream covers these requirements.  I think we need an fopen-,  fread-,
fwrite-like interface. It means what we will operate it as:

1. read byte

2. write byte (replace, insert, delete, etc...)

3. set position (increment n, decrement n, first, last, search by data sequence,
   etc...)

4. create

5. delete

These functions don't contain any information  about  size.   Size  must  update
dynamically and fit it's payload. Insertion must extend used memory and deleting
must free used memory and additional modiry current position if it needed.  

Read or write action operates stored  data  and  renew  current  pointer.   This
mechanism can be applied for access in any cases which we can  imagine  even  in
network applications. But for proof of concept we will use simple array in RAM
and adapter to it.

And first problem we need to solve how to set decimal string  into  binary.   In
common case recursively divide number by 2 and store carry.

```
123(10) = 123 | 2
          122 +---
          --- | 61 | 2
            1   60 +---
            |   -- | 30 | 2
            |    1   30 +---
            |    |   -- | 15 | 2
            |    |    0   14 +--
            |    |    |   -- | 7 | 2
            |    |    |    1   6 +--
            |    |    |    |   - | 3 | 2
            |    |    |    |   1   2 +--
            |    |    |    |   |   - | 1 | 2
            |    |    |    |   |   1   0 +--
            |    |    |    |   |   |   - | 0
            |    |    |    |   |   |   1
            |    |    |    |   |   |   |
            v    v    v    v   v   v   v
            1    1    0    1   1   1   1   0 <- big endian form
                                           |
            +------------------------------+
            |
            01111011                         <- little endian form
```

It's wery interesting tale about MSB, LSB, little and big endian orders  but  in
fact almost all of us have little endian machines at their homes with MSB order.
And in fact every byte we need to convert big endian form to little endian.  And
as we see we need a storage to mind results of every iteration.

Let's think about this temporary buffer. We will store it result of every
division and this number is possibly infinite lenght. But not greater than
origin number.

Another operative memory we need to every division in algorhytm. Let's see
school method of division which were used in old arithmometers too:

```
123456 | 2
12     +------
---    | 61728
 03
  2
  -
  14
  14
  --
   05
    4
    -
    16
    16
    --
     0 <-- carry
```

In every division iteration we use not greater than 2 digits and at  every  step
we forgot old results. Maximum number, which can be produced by 2 and anu number
we can reach in decimal form is 18 so we don't need many memory space  to  every
step of division.  For it we can use standard computer arithmetics  and  1  byte
operations will enough. As we have maximum operating value as 18 and it contains
2 digits, we can scan input string by 1 or 2 characters per iteration.

## what if code of another people is actually obfuscated...

![unseen](https://github.com/korrmet/scary_pit_of_monsters/raw/main/unseen.jpg)

As known work with code of another people is harder  than  work  with  code  you
implement yourself.  In normal situations this diffirence is not critical but in
real life you can see some people who becomes a source of unsupportable code.

I define these people for categories:
- newbie,
- fixes quick everything,
- trying to use language at 120 percents in any case even if it's no needed,
- proving his importance any method. (in text below self-prover)

I think your opinion is similar, maybe you have some additional categories.  But
it doesn't matter.  Really matters which kind of shittery they produce everyday.
For example we will take a look on a ioccc winners.  They are not  assholes  and
thy produce piece of art but distance between art and shit so close today.

## Example 1: unformatting

I know what may people talks what i have no format.  Actually i have.  Check out
eastman's ball:


```
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/ioctl.h>

             main() {
         short a[4];ioctl
      (0,TIOCGWINSZ,&a);int
    b,c,d=*a,e=a[1];float f,g,
  h,i=d/2+d%2+1,j=d/5-1,k=0,l=e/
 2,m=d/4,n=.01*e,o=0,p=.1;while (
printf("\x1b[H\x1B[?25l"),!usleep(
79383)){for (b=c=0;h=2*(m-c)/i,f=-
.3*(g=(l-b)/i)+.954*h,c<d;c+=(b=++
b%e)==0)printf("\x1B[%dm ",g*g>1-h
*h?c>d-j?b<d-c||d-c>e-b?40:100:b<j
||b>e-j?40:g*(g+.6)+.09+h*h<1?100:
 47:((int)(9-k+(.954*g+.3*h)/sqrt
  (1-f*f))+(int)(2+f*2))%2==0?107
    :101);k+=p,m+=o,o=m>d-2*j?
      -.04*d:o+.002*d;n=(l+=
         n)<i||l>e-i?p=-p
             ,-n:n;}}
```

Copy and paste it in main.c and compile with a command `gcc -lm  -ansi  main.c`.
After that start it using terminal emulator which apply VT100 sequences and  you
will see beautiful dynamic ASCII-art - white and red ball bouncing in  front  of
a gray wall.

But hard to understand how...  One  of  reasons  is  formatting.   There  is  no
formatting.

```c
#include <math.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

main() {
  short a[4];
  ioctl(0, TIOCGWINSZ, &a);
  int b, c, d = *a, e = a[1];
  float f, g, h, i = d / 2 + d % 2 + 1, j = d / 5 - 1, k = 0, l = e / 2,
                 m = d / 4, n = .01 * e, o = 0, p = .1;
  while (printf("\x1b[H\x1B[?25l"), !usleep(79383)) {
    for (b = c = 0;
         h = 2 * (m - c) / i, f = -.3 * (g = (l - b) / i) + .954 * h, c < d;
         c += (b = ++b % e) == 0)
      printf("\x1B[%dm ",
             g * g > 1 - h * h ? c > d - j
                                     ? b < d - c || d - c > e - b ? 40 : 100
                                 : b < j || b > e - j             ? 40
                                 : g * (g + .6) + .09 + h * h < 1 ? 100
                                                                  : 47
             : ((int)(9 - k + (.954 * g + .3 * h) / sqrt(1 - f * f)) +
                (int)(2 + f * 2)) %
                         2 ==
                     0
                 ? 107
                 : 101);
    k += p, m += o, o = m > d - 2 * j ? -.04 * d : o + .002 * d;
    n = (l += n) < i || l > e - i ? p = -p, -n : n;
  }
}
```

looks better, but isn't fine. 

### why?

In real life you can see something as:

```c
int main(int argc, char** argv)
{
  foo();
  bar();

        if (something)
        {
if (something_else)
{
printf("aa\n");
  printf("jjj\n");
}
  else
  {
printf("cc\n");
      printf("string %d\n", __LINE__);
}
printf("bb\n\n");
    
      printf("lll\n\n\n");
    }

return 0;
}
```

You can't explain where borders of if end else body  because  brackets  are  not
enough for correct positioning in multiple strings.  Your mind uses some another
ways to get position in structure of program like an idention.

This code may be result of copypasting existing parts.  Novices and quick-fixers
often do that but generally source of it are quick-fixers. 

Also  you  can  see,  what  this   code   contains   many   printf   with   junk
strings.  Quick-fixers often used something like that to debug  program  because
often it's really easier than break break debugger in some place.  Developer  so
hurried up so he can't imagine better name for his  debugging  output.   And  he
decided not to remove this junk because it require so much time. 

These behavour has some side effects which be displayed in next sections.  But i
must told you now what just formatting may break program in  mind  of  developer
which write this code. There used printf with line macro and developer will seek
in programs output old line number. Also you can really break program because if
earlier line number was 100  and  after  formatting  it  becomes  99  you  reach
situation where debugging printf makes shorter output and it  can  produse  some
side effect which can totally break application. 

### how to defeat it?

Now talk about how reach same effect.  I prefer to format code manually  because
i read code many times and often i'm have some ideas while i'm doing that.   But
today i used clang-formatter.  Manual formatting can produce some errors.  Don't
forget chech out what program works correctly in  any  case  especially  if  you
trying to do something manually. Also exists program called deobfuscators. It's
more complex programs and they also can delete  some  junk  code,  replace  some
constructions with more readable, etc.  I don't talk about it because i  haven't
money for this.

Will be cool if you try to recognize unformatted code in your mind before
formatting. This practice force you to think like a compiler parser.

```c
int main(int argc, char** argv)
{ foo(); bar();

  if (something)
  { if (something_else) { printf("aa\n"); printf("jjj\n"); }
    else                { printf("cc\n"); printf("string %d\n", __LINE__); }
    
    printf("bb\n\n"); printf("lll\n\n\n"); }
  
  return 0; }
```

This is result of manual formatting and it looks better.

## Example 2: undefined behavour so undefined

Undefined behavour is not means only `i += ++i + ++i`. As i display above it may
be result of almost anything.

```c
printf("            \r");
```

What do you think this statement doing? It prints some whitespaces which you can
see and after that returns carriage in zero position. For user this code does
makes no effect. So you decide to delete it because it's garbage and you will
right. But after deleting you will see what program crashes.

```c
//void* wait_message(mailbox_t* mail)
//void send_message(mailbox_t* mail, void* message) 
mailbox_t mailbox;

int some_func(void) { do_something_important(); return 1; }

void thread1(void)
{ int (*func_p)(void) = some_func;
  send_message(&mailbox, &func_p);
  printf("            \r"); 
  printf("            \r"); 
 
  thread_exit(); }

void thread2(void)
{ int (**func_p)(void) = NULL;
  while (1)
  { func_p = wait_message(&mailbox);
    if ((*funct_p)() != 1) { thread_exit(); } } }

int main()
{ thread_create(thread2);
  delay(1000);
  thread_create(thread1);

  while (1)
  { do_something_important_else(); }

  return 0; }
```

Example above based on my practice and  displays  main  mistake.   That  program
crashes at random time but faults were not often.  Let's  see  how  it  "works".
Thread one send message to thread two using special  synchronization  primitive.
Thread two is suspended  while  waiting  incoming  message.   Printf  calls  are
important because they perform zone where two threads exists in same moment  and
shedule can switch threads between two  printf  statements.   Sometimes  shedule
don't switch threads at this moment and thread2 runs  when  thread1  exited  and
pointer to func\_p is invalidated, program crashes.  If you try to change number
of whitespaces in printf states you can randomly change  fault  ratio.   If  you
delete one of them you increase fault ratio by 2 because now you have  just  one
place where threads can be switched.

### why?

Generally this kind of code produce people who every day trying to  prove  their
salary using dirty methods.  They inject similar code in project in many  places
and they control all project.  Fix this problems correctly is harder than  write
project again.  Companies often don't want to rewrite code in any  case  because
it requires to much money and time.  Also rewriting code can increase  power  of
self- because he can inject danger code in much more  places.   Also  this
code danger personally for you. Imagine what you have a task to fix something in
similar code.  You can spent months for it.  But after  that  self-prover  "fix"
problem in some hours.  Your manager can think what he is a good worker and  you
is a pice of shit.

### how to defeat it?

At first you must make sure what similar code owns one person and he  is  really
self-prover.  Secondary you must make sure what you able to defeat  him.   Often
that persons have families and childs. Do you really harm his wife and children?
Also prepare what succes rate is approximately 20 percents. May be less, but not
more. And finally prepare what you will have many dirty work to fix project.

Examine project how many code own potentially self-prover.  Quick look at it may
take enough information.  Estimate how much code infected  and  how  much  tasks
relates it.  If you think what it's too much for you just leave.  It means  what
team lead think what it's normal. Or may be team lead actually is self-prover.

If you sure what you can defeat it try to talk with him.   Self-provers  doesn't
admit their mistakes or weakness in some kind of tasks.  And he  actually  weak.
Examine his skills  but  prepare  what  he  can  lie.   Try  to  understand  his
motivation.  Sometimes you can see person who just do that they  can.   You  can
spend more time to work with him and teach to some good practices  and  he  will
fix danger code himself. But it's rare situation.

If previous has no effect talk with project manager or team lead.   Don't  speak
directly about danger person.  Find out why danger code was peoved and  included
in project.  Remember what it's in most cases is not a quick fix or  work  of  a
novice.  Examine what manager think about danger code.  If he agree  it  -  just
leave company at this stage.

After you knew managers point of view you have three ways:

- invalidate junk code using same methods and wait a moment when self-prover
  will spend month with task. It's dangerous way because you can perform
  deadline stalling.
- make test which displays danger of self-prover's code. Create some issues in
  bug tracker. Not so effective method because in real life companies which have
  danger code ignore all safety practices.
- open eyes of manager what danger code actually not pretty. Not so effective if
  self-prover has significant power. Maybe manager knows it but he can't do
  anything because he depend on self-prover. Also you can harm yourself.
- fork project and improve it in your private time. After that let manager look
  at that. Best way but hard.

Junk code can't be refactored. Rewrited only. Refactor techniques at present day
can't improve shit.

# Epilogue

See you later when i add some more monsters in this pit and  convert  my  shitty
English to normal. May the madness be with you.
