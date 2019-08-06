#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct CircleList
{
    int length;
    Node header;  //Í·½Úµã
}CircleList;

void InitList(CircleList*);
Node* CreateList(CircleList*, int);
void GetElem(CircleList*, int, int*);
void ListInsert(CircleList*, int, int);
void ListDelete(CircleList*, int, int*);


