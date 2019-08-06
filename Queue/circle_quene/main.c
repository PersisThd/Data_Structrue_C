#include <stdio.h>
#include <stdlib.h>
#include "circle_queue.h"

typedef struct stu
{
    int id;
    int age;
}student;

int main()
{
    cqueue cq;
    InitQueue(&cq);

    student s[MAXSIZE];
    int i = 0;


    //���ֻ�ܴ��MAXSIZE - 1������
    for(i = 0; i < MAXSIZE - 1; i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
        EnQueue(&cq, (void*)&s[i]);
    }
    printf("��ǰ���г���Ϊ��%d\n", QueueLength(&cq));

    for(i = 0; i < 5; i++)
    {
        student* tmp;
        GetFront(&cq, (void**)&tmp);
        printf("��ǰ��ͷԪ��Ϊ��id = %d, age = %d\n", tmp->id, tmp->age);
        DeQueue(&cq, (void**)&tmp);
        printf("��ǰ����Ԫ��Ϊ��id = %d, age = %d\n", tmp->id, tmp->age);
        printf("\n");
    }

    printf("��ǰ���г���Ϊ��%d\n", QueueLength(&cq));

    for(i = 0; i < 5; i++)
    {
        EnQueue(&cq, (void*)&s[i]);
    }
    printf("��ǰ���г���Ϊ��%d\n", QueueLength(&cq));

    ClearQueue(&cq);
    printf("��ǰ���г���Ϊ��%d\n", QueueLength(&cq));

    return 0;
}
