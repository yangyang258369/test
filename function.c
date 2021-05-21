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

char* func1( char* p)
{
  printf("%s\n", p);
  return p;
}

char* func2( char* p)
{
  printf("%s\n", p);
  return p;
}

char* func3( char* p)
{
  printf("%s\n", p);
  return p;
}

int main()
{
  void (*func_ptr)(int) = func;
  char* (*pf[3])(char *p);

  //函数指针赋值
  printf("%d\n", use(add,1,2));
  //函数指针赋值
  func_ptr(10);

  //函数指针数组
  pf[0] = func1;
  pf[1] = &func2;
  pf[2] = &func3;

  pf[0]("func1");
  pf[1]("func2");
  pf[2]("func3");

  return 0;
}


