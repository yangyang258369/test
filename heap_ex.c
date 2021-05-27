#include "stdio.h"
#include "string.h"

int main()
{
  int *p = (int*)malloc(20);

  for( int i = 0; i < 20; i++ )
  {
    p[i] = i;
    printf("p[%d] = %d\n", i, p[i]);
  }

  printf("int *p -> sizeof(p) = %d\n", sizeof(p));
  printf("(int*)malloc(20) -> sizeof((int*)malloc(20)) = %d\n", sizeof((int*)malloc(20)));



  printf("hello,world!\n");
  return 0;
}


