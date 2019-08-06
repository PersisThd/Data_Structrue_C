#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

typedef struct stu
{
    Node P;
    int id;
    int age;
}Student;

int main()
{
    Student s[10];
    LinkStack st;

    InitStack(&st);
    int i = 0;
    for(i = 0; i < (sizeof(s) / sizeof(s[0])); i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
    }

    for(i = 0; i < 10; i++)
    {
        PushStack(&st, &s[i].P);
    }

    for(i = 0; i < 5; i++)
    {
        Node* tmp;
        GetTop(&st, &tmp);
        Student* tmp1 = (Student*) tmp;
        printf("当前栈顶元素值为：id = %d, age = %d\n", tmp1->id, tmp1->age);

        PopStack(&st, &tmp);
        tmp1 = (Student*) tmp;
        printf("出栈元素值为：id = %d, age = %d\n", tmp1->id, tmp1->age);
        printf("\n");
    }

    printf("当前栈的大小为：%d\n", st.length);

    ClearStack(&st);
    printf("当前栈的大小为：%d\n", st.length);

    char str[] = "931-3*+82/+";
    convert(&st, str);


    return 0;
}
