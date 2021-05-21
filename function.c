#include "stdio.h"
#include "string.h"


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

void print_add( int a, int b )
{
  printf("add = %d\n", a + b);
}

void print_sub( int a, int b)
{
  printf("sub = %d\n", a - b);
}

int main()
{
  unsigned int ch;
  void (*func_ptr)(int) = func;
  void (*use_ptr[])(int,int) = (print_add, print_sub);

  scanf("%d", &ch);
  if( ch > 2 )
    return 0;

  printf("%d\n", use(add,1,2));
  func_ptr(10);

  (*use_ptr[ch])(1,5);

  return 0;
}


