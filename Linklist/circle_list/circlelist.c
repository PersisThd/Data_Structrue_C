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
    Node* tail = &L->header;

    for(i = 0; i < L->length; i++)
    {
        tail = tail->next;
    }

    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pNew = (Node*)malloc(sizeof(Node));

    if(pos == 0)
    {
        pNew->data = e;
        pNew->next = pCur->next;
        pCur->next = pNew;
        tail->next = pNew;
        L->length++;
        return;
    }

    if(pos == L->length)
    {
        pNew->data = e;
        pNew->next = tail->next;
        pCur->next = pNew;
        tail = pNew;
        L->length++;
        return;
    }


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
    Node* tail = &L->header;  //设定尾指针指向循环链表的尾部

    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        tail = tail->next;
    }


    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pDel = (Node*)malloc(sizeof(Node));

    if(pos == 0)
    {
        pDel = pCur->next;
        *e = pDel->data;
        pCur->next = pDel->next;
        tail->next = pDel->next;

        free(pDel);
        L->length--;
        return;
    }

    if(pos == L->length - 1)
    {
        pDel = pCur->next;
        *e = pDel->data;
        pCur->next = tail->next;
        tail = pCur;

        free(pDel);
        L->length--;
        return;
    }

    pDel = pCur->next;
    *e = pDel->data;
    pCur->next = pDel->next;

    free(pDel);

    L->length--;

}

void ListTest(CircleList* L)
{
    Node* p_h = &L->header;
    int i = 0;
    for(i = 0; i < 2 * L->length; i++)
    {
        p_h = p_h->next;
        printf("The value is: %d\n", p_h->data);
    }
}


void ClearList(CircleList* L)
{
    while(L->length != 0)
    {
        int tmp;
        ListDelete(L, 0, &tmp);
    }
}

void Josephus(CircleList* L)
{
    printf("请输入第一个出列人的序号：\n");
    int pos;
    scanf("%d", &pos);

    printf("请输入数到m就出列的m值：\n");
    int num;
    scanf("%d", &num);

    Node* pCur = &L->header;
    Node* tail = &L->header;

    while(pCur->data != pos)
    {
        tail = pCur;  //保证tail指针永远指向pCur指针的上一个位置
        pCur = pCur->next;
    }

    int i = 0;
    while(pCur->next != pCur)  //p->next = p时表面链表中只剩下一个p结点
    {
        for(i = 0; i < num - 1; i++)
        {
            tail = pCur;
            pCur = pCur->next;
        }

        tail->next = pCur->next;
        printf("出列的人编号为：%d\n", pCur->data);
        free(pCur);

        pCur = tail->next;

    }

    printf("圆桌上最后留下人的编号为：%d\n", pCur->data);

}
