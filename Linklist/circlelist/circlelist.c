#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circlelist.h"


void InitList(CircleList* L)
{
    L->header.next = NULL;
    L->length = 0;
}

Node* CreateList(CircleList* L, int n)
{
    int i = 0;
    int num = 0;
    Node* pCur = &L->header;
    Node* head = &L->header;
    for(i = 0; i < n; i++)
    {
        printf("Input value: \n");
        scanf("%d", &num);
        Node* pNew = (Node*)malloc(sizeof(Node));

        pNew->data = num;
        pNew->next = NULL;

        pCur->next = pNew;
        pCur = pCur->next;
        L->length++;
    }
    pCur->next = head->next;

    return head;
}


void GetElem(CircleList* L, int pos, int *e)
{
    if(pos < 0 || pos > L->length)
        return;
    if(L->length == 0)
        return;

    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos + 1; i++)
    {
        pCur = pCur->next;
    }

    *e = pCur->data;

}

int ListLength(CircleList* L)
{
    return L->length;
}

int ListEmpty(CircleList* L)
{
    if(L->length == 0)
        return 1;

    return 0;
}

void ListInsert(CircleList* L, int pos, int e)
{
    if(pos < 0 || pos > L->length)
        return;

    int i = 0;
    Node* pCur = &L->header;
    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pNew = (Node*)malloc(sizeof(Node));
    pNew->data = e;
    pNew->next = pCur->next;
    pCur->next = pNew;

    L->length++;
}

void ListDelete(CircleList* L, int pos, int* e)
{
    if(pos < 0 || pos >= L->length)
        return;
    if(L->length == 0)
        return;

    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pDel = (Node*)malloc(sizeof(Node));

    pDel = pCur->next;
    *e = pDel->data;
    pCur->next = pDel->next;

    free(pDel);

    L->length--;



}

