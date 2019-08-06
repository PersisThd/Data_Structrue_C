#include <stdio.h>

typedef struct Node
{
    struct Node* next;
    struct Node* prior;
}Node;

typedef struct DoubleNode
{
    Node node;
    void* data;
}DoubleNode;

typedef struct DoubleList
{
    DoubleNode header;
    int length;
}DoubleList;



void InitList(DoubleList*);
int ListEmpty(DoubleList*);
int ListLength(DoubleList*);
void ListInsert(DoubleList*, int, void*);
void PrintList(DoubleList*);
void PrintList_Reverse(DoubleList*);
void CreateList(DoubleList*, int);
void ListDelete(DoubleList*, int, void**);
void GetElem(DoubleList*, int, void**);
void ClearList(DoubleList*);
void DestroyList(DoubleList*);
