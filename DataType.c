#include "stdio.h"
#include "string.h"

struct a0
{
  char a; //1
};

struct a1
{
  int a;//4
};

struct a2
{
  short a;//4
};

struct a3
{
  float a;//8
};

struct a4
{
  double a;//8
};

struct a5
{
  int a;   //4
  char b;  //此整数倍对齐，则此处为2
  short c; //2
};

struct a6
{
  char a; //4
  int b;  //4
  short c;//4
};

struct a7
{
  char a; //4
  int b;  //4
  double c;//8
};

struct a8
{
  int a;  //4
  char b; //4
  int c;  //4
};

struct a9
{
  int a;  //4
  char b; //4
  double c;  //4
};


int main()
{
  int a = 5;
  char c = 'a';
  float f = 5.3;
  double m = 12.65;
  double result = 0;

  printf(" sizeof(a) = %d, sizeof(c) = %d,sizeof(c) = %d,sizeof(m) = %d\n", sizeof(a), sizeof(c), sizeof(f), sizeof(m));
  printf(" sizeof(struct a0) = %d, sizeof(struct a1) = %d\n", sizeof(struct a0), sizeof(struct a1) );
  printf(" sizeof(struct a2) = %d, sizeof(struct a3) = %d\n", sizeof(struct a2), sizeof(struct a3) );
  printf(" sizeof(struct a4) = %d, sizeof(struct a5) = %d\n", sizeof(struct a4), sizeof(struct a5) );
  printf(" sizeof(struct a6) = %d, sizeof(struct a7) = %d\n", sizeof(struct a6), sizeof(struct a7) );
  printf(" sizeof(struct a8) = %d, sizeof(struct a9) = %d\n", sizeof(struct a8), sizeof(struct a9) );

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


