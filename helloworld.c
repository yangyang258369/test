#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

//大的内存块
typedef struct linear_block
{
  /* data */
  struct  linear_block *next;  
}linear_block_t;

//线性分配器
typedef struct linear_allocator
{
  /* data */
  linear_block_t *header;
  unsigned char *end;
  size_t blksz;
}linear_allocator_t;

//最小的块大小
#define         LINEAR_MIN_BLOCK_SIZE      1024
//内存块头大小
#define         HEADER_SIZE                sizeof(linear_block_t)
//取内存块的Buffer
#define         LINEAR_BUFFER(b)           ((unsigned char*)(b) + HEADER_SIZE)

//初始化
static void linear_init( linear_allocator_t *a, size_t size )
{
  a->blksz = size + HEADER_SIZE < LINEAR_MIN_BLOCK_SIZE ? LINEAR_MIN_BLOCK_SIZE : size + HEADER_SIZE;
  a->header = NULL;
  a->end = (unsigned char*)HEADER_SIZE;   //此举是为了在分配时减少一次判断
}

//分配内存器
static inline linear_block_t* _linear_new_block( size_t size )
{
  return (linear_block_t*)malloc(size);
}

//分配内存
static void* linear_allc( linear_allocator_t *a, size_t size )
{
  if(a->end - LINEAR_BUFFER(a->header) < size)//内存不足，分配新的内存块
  {
      if( size + HEADER_SIZE > a->blksz )
      {
        //如果请求的大小比默认内存块大，则尝试创建更大的内存块
        linear_block_t *block = _linear_new_block(HEADER_SIZE + size);
        unsigned char *buffer = LINEAR_BUFFER(block);
        if( a->header != NULL )
        {
          block->next = a->header->next;
          a->header->next = block;
        }
        else
        {
          //如果头结点不存在，则成为头结点
          block->next = NULL;
          a->header = block;
          a->end = buffer;
        }
        return buffer;
      }
      else
      {
        //否则正常分配内存块，并成为链表头
        linear_block_t *block = _linear_new_block(a->blksz);
        block->next = a->header;
        a->header = block;
        a->end = (unsigned char*)block + a->blksz;
      }
  }
  a->end -= size;
  return a->end;
}

//终止
static void linear_term( linear_allocator_t *a )
{
  linear_block_t *block = a->header;
  linear_block_t *temp;

  while(block)
  {
    temp = block;
    block = block->next;
    free(temp);
  }
}

int main()
{
  //linear_init();

  printf("hello,world!\n");
  return 0;
}


