#include "stdio.h"
#include "string.h"

int main()
{
  int *p = (int*)malloc(20);
  int *n = NULL;
  int i = 0;

  for( i = 0; i < 20; i++ )
  {
    p[i] = i;
    printf("p[%d] = %d\n", i, p[i]);
  }

  printf("int *p -> sizeof(p) = %d\n", sizeof(p));
  printf("int *n -> sizeof(n) = %d\n", sizeof(n));

  for ( i = 0; i < 20; i++)
  {
   printf("malloc[%d] = %s\n", i, p[i]);
  }

  printf("hello,world!\n");

  free(p);

  return 0;
}


