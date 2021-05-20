#include "stdio.h"
#include "string.h"

struct a1
{
  int a;
  char b;
  short c;
};

struct a2
{
  char a;
  int b;
  short c;
};

int main()
{
  int a = 5;
  char c = 'a';
  float f = 5.3;
  double m = 12.65;
  double result = 0;
  struct a1 stu_a1;
  struct a2 stu_a2;

  printf(" sizeof(a) = %d, sizeof(c) = %d,sizeof(c) = %d,sizeof(m) = %d\n", sizeof(a), sizeof(c), sizeof(f), sizeof(m));
  printf(" sizeof(struct a) = %d, sizeof(struct b) = %d\n", stu_a1, stu_a2):

  //同类型数据间运算并输出结果
  printf("a + c = %d\n", a+c);//int转char
  printf("a + c = %c\n", a+c);
  printf("f + m = %f\n", f+m);

  //不同类型数据间进行运算并输出结果
  printf("a + m = %f\n", a+m);
  printf("c + f = %f\n", c+f);

  //将上述四个变量进行混合运算，并输出结果
  result = a + c * (f + m);
  printf("double = %f\n", result);

  return 0;
}


