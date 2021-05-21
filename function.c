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

int main()
{
  printf("%d\n", use(add,1,2));  
  return 0;
}


