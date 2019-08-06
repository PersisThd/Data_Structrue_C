#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_doublelist.h"

int main()
{
    DoubleList ls;
    InitList(&ls);
    printf("The length is %d\n", ls.length);

    printf("请输入链表的长度：\n");
    int len = 0;
    scanf("%d", &len);
    getchar();  //吞并掉缓冲区中的回车符

    CreateList(&ls, len);


    PrintList(&ls);
    PrintList_Reverse(&ls);

    void* tmp;
    ListDelete(&ls, 0, &tmp);
    PrintList_Reverse(&ls);
    //PrintList(&ls);

    ListDelete(&ls, ls.length-1, &tmp);
    PrintList(&ls);
    char tmp1[20] = "Zhangjiajia";
    ListInsert(&ls, ls.length, &tmp1);
    PrintList(&ls);

    char tmp2[20] = "Tanhuadong";
    ListInsert(&ls, 0, &tmp2);
    PrintList(&ls);

    GetElem(&ls, 0, &tmp);
    printf("tmp = %s\n", (char*)tmp);

    GetElem(&ls, ls.length-1, &tmp);
    printf("tmp = %s\n", (char*)tmp);

    ClearList(&ls);
    printf("链表当前长度为：%d\n", ls.length);
    DestroyList(&ls);


    return 0;
}
