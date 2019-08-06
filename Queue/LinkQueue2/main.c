#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

typedef struct stu
{
    int id;
    int age;
}student;

int main()
{
    LinkQueue lq;
    InitQueue(&lq);
    student s[10];

    int i = 0;
    for(i = 0; i < 10; i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
        EnQueue(&lq, &s[i]);

    }

    printf("��ǰ���еĳ���Ϊ��%d\n", QueueLength(&lq));

    while(!QueueEmpty(&lq))
    {
        student* tmp;
        GetFront(&lq, (void**)&tmp);
        printf("��ǰ��ͷԪ��ֵΪ��id = %d, age = %d\n", tmp->id, tmp->age);

        DeQueue(&lq, (void**)&tmp);
        printf("��ǰ����Ԫ��ֵΪ��id = %d, age = %d\n", tmp->id, tmp->age);
        printf("\n");
    }
    printf("��ǰ���еĳ���Ϊ��%d\n", QueueLength(&lq));

    EnQueue(&lq, &s[0]);
    ClearQueue(&lq);
    printf("��ǰ���еĳ���Ϊ��%d\n", QueueLength(&lq));

    return 0;
}
