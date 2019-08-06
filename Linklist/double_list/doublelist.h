#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prior;
}Node;

typedef struct DoubleList
{
    int length;
    Node header;
}DoubleList;

void InitList(DoubleList*);
int ListEmpty(DoubleList*);
int ListLength(DoubleList*);
void ListInsert(DoubleList*, int, int);
void PrintList(DoubleList*);
void PrintList_Reverse(DoubleList*);
void CreateList(DoubleList*, int);
void ListDelete(DoubleList*, int, int*);
void GetElem(DoubleList*, int, int*);
void ClearList(DoubleList*);
void DestroyList(DoubleList*);
