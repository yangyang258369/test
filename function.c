#include "stdio.h"
#include "string.h"

void print_add( int a, int b );
void print_sub( int a, int b);

int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

int use(int (*binfunc)(int a, int b), int a, int b)
{
  return (*binfunc)(a, b);
}

void func( int a )
{
  printf("Input of Data = %d\n", a);
}

int main()
{
  unsigned int ch, a, b;
  void (*func_ptr)(int) = func;
  void (*use_ptr[])(int,int) = (print_add, print_sub);

  scanf("%d", &ch);
  if( ch > 2 )
    return 0;

  printf("%d\n", use(add,1,2));
  func_ptr(10);

  a = 15;
  b = 10;
  (*use_ptr[ch])(a,b);

  return 0;
}


void print_add( int a, int b )
{
  printf("add = %d\n", a + b);
}

void print_sub( int a, int b)
{
  printf("sub = %d\n", a - b);
}

