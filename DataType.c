#include "stdio.h"
#include "string.h"

struct a0
{
  char a;
};

struct a1
{
  int a;
};

struct a2
{
  short a;
};

struct a3
{
  float a;
};

struct a4
{
  double a;
};

struct a5
{
  int a;
  char b;
  short c;
};

struct a6
{
  char a;
  int b;
  short c;
};

struct a7
{
  char a;
  int b;
  double c;
};

int main()
{
  int a = 5;
  char c = 'a';
  float f = 5.3;
  double m = 12.65;
  double result = 0;
  struct a0 stu_a0;
  struct a1 stu_a1;
  struct a2 stu_a2;
  struct a3 stu_a3;
  struct a4 stu_a4;
  struct a5 stu_a5;
  struct a6 stu_a6;
  struct a7 stu_a7;

  printf(" sizeof(a) = %d, sizeof(c) = %d,sizeof(c) = %d,sizeof(m) = %d\n", sizeof(a), sizeof(c), sizeof(f), sizeof(m));
  printf(" sizeof(struct a0) = %d, sizeof(struct a1) = %d\n", sizeof(stu_a0), sizeof(stu_a1) );
  printf(" sizeof(struct a2) = %d, sizeof(struct a3) = %d\n", sizeof(stu_a2), sizeof(stu_a3) );
  printf(" sizeof(struct a4) = %d, sizeof(struct a5) = %d\n", sizeof(stu_a4), sizeof(stu_a5) );
  printf(" sizeof(struct a6) = %d, sizeof(struct a7) = %d\n", sizeof(stu_a6), sizeof(stu_a7) );

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


