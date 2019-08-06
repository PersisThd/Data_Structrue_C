#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct CircleList  //用于管理循环链表
{
    int length;
    Node header;  //头节点
}CircleList;

void InitList(CircleList*);  //链表的初始化
Node* CreateList(CircleList*, int);  //创建循环链表
void GetElem(CircleList*, int, int*);  //取出循环链表中的指定位置的元素值
void ListInsert(CircleList*, int, int);  //循环链表的插入操作
void ListDelete(CircleList*, int, int*);  //循环链表的删除操作
int ListEmpty(CircleList*);  //判断循环链表是否为空
int ListLength(CircleList*);  //返回循环链表的长度
void ListTest(CircleList*);
void ClearList(CircleList*);
void Josephus(CircleList*);
