#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
  int *p = (int*)malloc(20);                   //申请20字节
  int *r = (int*)malloc(sizeof(int) * 5);      //申请20字节
  int *n = NULL;
  int i = 0;

  for( i = 0; i < 20; i++ )
  {
    p[i] = i;
    printf("p[%d] = %d\n", i, p[i]);
  }

  //指针大小
  printf("int *p -> sizeof(p) = %d\n", sizeof(p));
  printf("int *n -> sizeof(n) = %d\n", sizeof(n));

  //指针地址
  printf("addr p = 0x%x\n", p);

  //缓存指针地址
  for( i = 0; i < 4; i++ )
  {
    p[i] = i;
    printf("(%d)%d, %x\n", i, p[i], &p[i]);
  }

  printf("hello,world!\n");

  free(p);
  free(r);

  return 0;
}


