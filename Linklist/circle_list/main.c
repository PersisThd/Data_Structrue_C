#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

int main()
{
    printf("��������������\n");
    int len;
    scanf("%d", &len);

    CircleList ls;
    InitList(&ls);
    CreateList(&ls, len);

//  ѭ���������

    ListTest(&ls);
    printf("\n");


    int tmp;

    ListDelete(&ls, 0, &tmp);
    ListTest(&ls);
    printf("\n");

    ListDelete(&ls, ls.length-1, &tmp);
    ListTest(&ls);
    printf("\n");

    ListInsert(&ls, 0, 1);
    ListTest(&ls);
    printf("\n");

    ListInsert(&ls, ls.length, 5);
    ListTest(&ls);
    printf("\n");


//  Լɪ��ʵ��
    Josephus(&ls);

//  �������
    ClearList(&ls);
    printf("������Ϊ��%d\n", ls.length);

    return 0;
}
