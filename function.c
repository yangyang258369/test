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
  void (*func_ptr)(int) = func;

  printf("%d\n", use(add,1,2));
  func_ptr(10);

  return 0;
}


