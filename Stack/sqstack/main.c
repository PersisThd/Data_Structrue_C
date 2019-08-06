#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

typedef struct student
{
    int age;
    int id;
}stu;

int main()
{
    SqStack st;
    stu s[10];

    InitStack(&st);

    int i = 0;
    for(i = 0; i < 10; i++)
    {
        s[i].age = i + 20;
        s[i].id = i;
        PushStack(&st, &s[i]);
    }
    printf("当前栈的大小为：%d\n", StackLength(&st));

    stu* sp;
    for(i = 0; i < 5; i++)
    {
        GetTop(&st, (void**)&sp);
        printf("当前栈顶元素值为：%d, %d\n", sp->age, sp->id);

        PopStach(&st, (void**)&sp);
        printf("出栈元素值为：%d, %d\n", sp->age, sp->id);
        printf("\n");
    }

    printf("当前栈的大小为：%d\n", StackLength(&st));

    ClearStack(&st);
    printf("当前栈的大小为：%d\n", StackLength(&st));


    //printf("Hello world!\n");
    return 0;
}
