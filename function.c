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

int main()
{
  unsigned int ch;
  void (*func_ptr)(int) = func;
  int (*use_ptr[])(int,int) = (add, sub);

  scanf("%d", &ch);
  if( ch > 2 )
    return 0;

  printf("%d\n", use(add,1,2));  
  func_ptr(10);

  (*use_ptr[ch])(1,5);

  return 0;
}


