#include <stdio.h>


typedef struct Node
{
    struct Node* next;
}Node;

typedef struct ListNode
{
    Node node;
    void* data;
}ListNode;

typedef struct LINKLIST
{
    int length;
    ListNode header;
}LINKLIST;

void InitList(LINKLIST*);
int ListEmpty(LINKLIST*);
int ListLength(LINKLIST*);
void GetElem(LINKLIST*, int, void **);
void ListInsert(LINKLIST*, int, void*);
void ListDel(LINKLIST*, int, void **);
void ClearList(LINKLIST*);
void DestroyList(LINKLIST*);
