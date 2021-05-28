#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
  int *p = (int*)malloc(20);                   //申请20字节
  int *r = (int*)malloc(sizeof(int) * 5);      //申请20字节
  int *n = NULL;
  int i = 0;

  //for( i = 0; i < 10; i++ )    //此时数据越界，最大为5，此时为10  释放是会报错误
  for( i = 0; i < 4; i++ )
  {
    p[i] = i;
    printf("p[%d] = %d\n", i, p[i]);
  }

  //指针大小
  printf("int *p -> sizeof(p) = %ld\n", sizeof(p));
  printf("int *n -> sizeof(n) = %ld\n", sizeof(n));

  //指针地址
  printf("addr p = %p\n", p);

  //缓存指针地址
  for( i = 0; i < 4; i++ )
  {
    p[i] = i;
    printf("(%d)%d, %p\n", i, p[i], &p[i]);
  }

  printf("hello,world!\n");

  free(p);
  free(r);

  return 0;
}


