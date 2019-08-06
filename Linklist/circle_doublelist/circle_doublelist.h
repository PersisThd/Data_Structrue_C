#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prior;
}Node;

typedef struct cir_doublelist
{
    Node header;
    int length;
}cir_doublelist;

void InitList(cir_doublelist*);
int ListEmpty(cir_doublelist*);
int ListLength(cir_doublelist*);
Node* CreateList(cir_doublelist*, int);
void ListTest(cir_doublelist*, int);
void ListTest_Reverse(cir_doublelist*, int);
void ListDelete(cir_doublelist*, int, int*);
void ListInsert(cir_doublelist*, int, int);
void GetElem(cir_doublelist*, int, int*);
void ClearList(cir_doublelist*);
void DestroyList(cir_doublelist*);
