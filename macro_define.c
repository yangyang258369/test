#include "stdio.h"
#include "string.h"

#define  SECOND_PER_YEAR   (60*60*24*365)UL
#define  MIN(A,B)          ((A)<=(B)?(A):(B))
#define  MAX(A,B)          ((A)>=(B)?(A):(B))


int main()
{
  printf("MIN = %d\n", MIN(7,9));
  printf("MIN = %d\n", MIN(8,3));
  printf("MAX = %d\n", MAX(7,9));
  printf("MAX = %d\n", MAX(8,3));

  return 0;
}


