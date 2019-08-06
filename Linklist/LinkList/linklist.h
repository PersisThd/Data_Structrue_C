#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;  //定义链表结构

typedef struct LINKLIST
{
    int length;
    Node header;
}LINKLIST;  //操控链表

void InitList(LINKLIST*);  //初始化链表
int ListEmpty(LINKLIST*);  //判断链表是否为空
int ListLength(LINKLIST*);  //返回链表长度
void GetElem(LINKLIST*, int, int *);  //获取指定位置的元素（pos从0开始）
void ListInsert(LINKLIST*, int, int); //在指定位置中插入新元素
void ListDel(LINKLIST*, int, int *);  //删除指定位置的元素
void ClearList(LINKLIST*);  //清空链表
void DestroyList(LINKLIST*);  //销毁链表
