
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct list_node
{
  int data;                //数据域，用于存储数据
  struct list_node *next;  //指针，可以用来访问节点数据，也可以遍历，指向下一个节点
};

typedef struct list_node list_single;

//创建链表
list_single *create_list_node( int data )
{
  list_single *node = NULL;                              //首先，定义一个头指针
  node = (list_single*)malloc(sizeof(list_single));      //分配内存空间
  if( NULL == node )
  {
    printf("malloc fail!\n");
  }

  memset(node, 0, sizeof(list_single));                  //清空内存空间
  node->data = data;                                     //给链表节点的数据赋值
  node->next = NULL;                                     //将链表的指针域指向空

  return node;
}

//链表的尾插
void tail_insert( list_single *pH, list_single *new )
{
  list_single *p = pH;                                   //获取当前位置
  while ( NULL != p->next )                              //如果当前位置的下一个节点不为空
  {
    p = p->next;                                         //移动到下一个节点
  }
  p->next = new;                                         //如果跳出以上循环，所以已经到了NULL的这个位置，此时直接把新插入的节点赋值给NULL这个位置
}

//链表的头插
void top_insert( list_single *pH, list_single *new)
{
  list_single *p = pH;                                   //获取当前位置
  new->next = p->next;                                   //此时把前一节点的数据赋值给新插入的节点
  p->next = new;                                         //把新插入的节点赋值给前一节点的指针
}

//链表的遍历
void print_node( list_single *pH )
{
  list_single *p = pH;                                   //获取当前位置
  p = p->next;                                           //获取第一个节点的位置
  while( NULL != p->next )
  {
    printf("data:%d\n", p->data);                        //打印节点的数据内容
    p = p->next;                                         //移动到下一节点，如果条件仍为真，则重复(1)，再(2)
  }
  printf("data:%d\n", p->data);                          //如果当前节点位置的下一个节点为NULL，则打印数据 说明只有一个节点
} 

//删除链表中的节点
int delete_list_node( list_single *pH, int data )
{
  list_single *p = pH;                                   //获取当前位置
  list_single *prev = NULL;
  while( NULL != p->next )
  {
    prev = p;                                            //保存当前节点的一个节点的指针
    p = p->next;                                         //然后让当前的指针继续往后移动
    if( p->data == data )
    {
      //两种情况，一种为普通节点，还有一种是尾节点
      if( p->next != NULL )                              //普通节点
      {
        prev->next = p->next;
        free(p);
      }
      else                                               //尾节点
      {
        prev->next = NULL;                               //将这个尾结点的上一个节点的指针域指向空
        free(p);
      }
    }
  }
  printf("没有要删除的节点\n");
  return -1;
}

void trave_list( list_single *pH )
{
  list_single *p = pH->next;
  list_single *pBack;
  int i = 0;

  if( p->next == NULL | p == NULL )
  {
    return;
  }

  while( NULL != p->next )//遍历链表
  {
    pBack = p->next;                                    //保存第一个节点的下一个节点
    if( p == p->next )                                  //找到第一个有效节点，其实就是头指针的下一个节点
    {
      p->next = NULL;                                   //第一个有效节点就是最后一个节点，所以要指向NULL
    }
    else
    {
      //new->next = p->next;
      //p->next = new;
      p->next = pH->next;                               //尾部连接
    }
    pH->next = p;                                       //头部连接
    p = pBack;                                          //走下一个节点
  }
  top_insert(pH, p);                                    //插入最后一个节点
}

int main()
{
#if 0      //链表创建单节点  
  int data = 100;

  list_single *node_ptr = create_list_node(data); //创建一个节点
  printf("node_ptr->data = %d\n", node_ptr->data);
  printf("node_ptr->next = %d\n", node_ptr->next);

  free(node_ptr);
#endif
#if 1      //链表实验
  int i;
  list_single *header = NULL; 
  header = create_list_node(0);
  printf("data = %d\n", header->data);
  header = create_list_node(1);
  printf("data = %d\n", header->data);
  
  // for ( i = 1; i < 10; i++)
  // {
  //   tail_insert(header, create_list_node(i));
  //   printf("data[%d] = %d\n", i, header->data);
  // }
  
//  print_node(header);
//  delete_list_node(header, 5);
//  putchar('\n');
//  print_node(header);
//  putchar('\n');
//  trave_list(header);
//  print_node(header);

#endif

  return 0;
}