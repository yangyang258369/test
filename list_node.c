
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct list_node
{
  /* data */
  int data;                //数据域，用于存储数据
  struct list_node *next;  //指针，可以用来访问节点数据，也可以遍历，指向下一个节点
};

typedef struct list_node list_single;

list_single *create_list_node( int data )
{
  list_single *node = NULL;                              //首先，定义一个头指针
  node = (list_single*)malloc(sizeof(list_single));      //分配内存空间
  if( NULL == node )
  {
    printf("malloc fail!\n");
  }

  memset(node, 0, sizeof(list_single));                  //请客内存空间
  node->data = data;                                     //给链表节点的数据赋值
  node->next = NULL;                                     //将链表的指针域指向空

  return node;
}

int main()
{
  int data = 100;

  list_single *node_ptr = create_list_node(data); //创建一个节点
  printf("node_ptr->data = %d\n", node_ptr->data);
  printf("node_ptr->next = %d\n", node_ptr->next);

  free(node_ptr);
  return 0;
}