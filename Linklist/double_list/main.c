#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

int main()
{
    DoubleList ls;
    InitList(&ls);
    printf("The length is %d\n", ls.length);
/*
    int i = 0;
    for(i=0;i<3;i++)
    {
        ListInsert(&ls, i, i+2);
    }
    printf("The length is %d\n", ls.length);
    ListInsert(&ls, 0, 10);
    printf("The length is %d\n", ls.length);

    PrintList(&ls);
    PrintList_Reverse(&ls);*/

    printf("请输入链表的长度：\n");
    int len = 0;
    scanf("%d", &len);
    CreateList(&ls, len);
    PrintList(&ls);
    PrintList_Reverse(&ls);
    int tmp;
    ListDelete(&ls, ls.length-1, &tmp);
    PrintList(&ls);
    ListDelete(&ls, 0, &tmp);
    PrintList(&ls);
    ListInsert(&ls, ls.length, 5);
    PrintList(&ls);
    ListInsert(&ls, 0, 1);
    PrintList(&ls);

    GetElem(&ls, 0, &tmp);
    printf("tmp = %d\n", tmp);
    GetElem(&ls, ls.length-1, &tmp);
    printf("tmp = %d\n", tmp);

    ClearList(&ls);
    printf("链表当前长度为：%d\n", ls.length);
    DestroyList(&ls);


    return 0;
}
