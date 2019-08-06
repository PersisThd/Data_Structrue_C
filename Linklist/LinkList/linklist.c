#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void InitList(LINKLIST* L)
{
    L->length = 0;
    L->header.next = NULL;
}

int ListEmpty(LINKLIST* L)
{
    if(L->length == 0)
        return 1;
    return 0;
}

int ListLength(LINKLIST* L)
{
    return L->length;
}

void GetElem(LINKLIST *L, int pos, int *e)
{
    if(pos < 0 || pos >= L->length)
        return;
    if(L->length == 0)
        return;

    Node *pCur = &L->header;

    int i = 0;
    for(i=0;i<pos+1;i++)
    {
        pCur = pCur->next;
    }
    *e = pCur->data;
}

void ListInsert(LINKLIST *L, int pos, int e)
{
    if(pos < 0 || pos > L->length)
        return;

    Node* pCur = &L->header;
    int i = 0;
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

void ListDel(LINKLIST* L, int pos, int *e)
{
    if(pos < 0 || pos >= L->length)
        return;
    if(L->length == 0)
        return;

    Node* pCur = &L->header;
    int i = 0;
    for(i=0;i<pos;i++)
    {
        pCur = pCur->next;
    }

    Node* pDel = pCur->next;
    *e = pDel->data;
    pCur->next = pDel->next;

    free(pDel);
    L->length--;
}

void ClearList(LINKLIST *L)
{
    while(ListEmpty(L) != 1)
    {
        int tmp;
        ListDel(L, 0, &tmp);
    }
}

void DestroyList(LINKLIST *L)
{
    ClearList(L);
}
