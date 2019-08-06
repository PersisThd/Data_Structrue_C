#include "linkstack2.h"
#include <stdlib.h>

void InitStack(LinkStack* st)
{
    st->length = 0;
    st->top = NULL;
}

int StackEmpty(LinkStack* st)
{
    if(st->length == 0)
        return 1;

    return 0;
}

int StackLength(LinkStack* st)
{
    return st->length;
}

void GetTop(LinkStack* st, void** e)
{
    if(st->length == 0)
    {
        printf("空栈！\n");
        return;
    }

    *e = st->top->data;

}

void PushStack(LinkStack* st, void* e)
{
    StackNode* pNew = (StackNode*)malloc(sizeof(StackNode));
    pNew->data = e;
    pNew->node.next = &st->top->node;
    st->top = pNew;
    st->length++;
}

void PopStack(LinkStack* st, void** e)
{
    StackNode* pDel = st->top;
    *e = pDel->data;
    st->top = (StackNode*)pDel->node.next;

    free(pDel);
    st->length--;
}

void ClearStack(LinkStack* st)
{
    if(st->length == 0)
    {
        printf("空栈！\n");
        return;
    }
    while(st->length)
    {
        void* tmp;
        PopStack(st, &tmp);
    }

}

int isleft(char c)
{
    int flag;
    switch(c)
    {
        case '[':
        case '{':
        case '(':
        case '<':
        case '\"':
        case '\'':
            flag = 1;
            break;
        default:
            flag = 0;
            break;
    }

    return flag;
}

int isright(char c)
{
    int bl;
    switch(c)
    {
        case ']':
        case '}':
        case ')':
        case '>':
            bl = 1;
            break;
        default:
            bl = 0;
            break;
    }

    return bl;
}

int isMatch(char left, char right)
{
    int bl;
    switch(left)
    {
    case '[':
        bl = (right == ']');
        break;
    case '{':
        bl = (right == '}');
        break;
    case '(':
        bl = (right == ')');
        break;
    case '<':
        bl = (right == '>');
        break;
    default:
        bl = 0;
    }

    return bl;
}

int isnumber(char c)
{
    if(c <= '9' && c >= '0')
    {
        return 1;
    }

    return 0;
}

int isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int priority(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(isleft(c))
    {
        return 0;
    }
    else
    {
        printf("符号出错，无法判断优先级！");
        return -1;
    }
}

int cacluate(int left, int right, char c)
{
    int result;
    switch(c)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = left / right;
        break;
    default:
        break;
    }

    return result;
}


void NearMatch(LinkStack* st, const char* p)
{
    int i = 0;
    while(p[i] != '\0')
    {

        if(isleft(p[i]))
        {
            PushStack(st, (void*)&p[i]);
        }

        else if(isright(p[i]))
        {
            if(st->length == 0)
            {
                printf("缺少左括号！\n");
                break;
            }
            else
            {
                 char* tmp;
                 PopStack(st, (void**)&tmp);
                 //char* tmp1 = (char*)tmp;
                 if(!isMatch(*tmp, p[i]))
                 {
                     printf("匹配成功！\n");
                     break;
                 }
            }

        }
        i++;
    }

    if(p[i] == '\0' && st->length == 0)
    {
        printf("匹配成功！\n");
    }
    else
    {
        printf("匹配失败！\n");
    }

}


/*
中缀表达式转后缀表达式算法思路：
遍历中缀表达式中的数字和符号：
    对于数字：直接输出
    对于符号：
              左括号：进栈
              运算符号：与栈顶符号进行优先级比较
                        若栈顶符号优先级低，则此符号进栈
                        （默认栈顶若是左括号，左括号优先级最低）
                        若栈顶符号优先级不低，将栈顶符号弹出并输出，之后进栈
              右括号：将栈顶符号弹出并输出，直到匹配到左括号
    遍历结束：弹出栈中所以符号并输出

*/
void ConvertExpression(LinkStack* st, char *p)
{
    int i = 0;
    while(p[i] != '\0')
    {
        if(isnumber(p[i]))
        {
            printf("%c", p[i]);
        }

        else if(isleft(p[i]))
        {
            PushStack(st, &p[i]);
        }

        else if(isoperator(p[i]))
        {
            char* tmp;

            if(st->length)
            {
                GetTop(st, (void**)&tmp);
                while(priority(*tmp) >= priority(p[i]) && st->length != 0 && !isleft(*tmp))
                {
                    PopStack(st, (void**)&tmp);
                    printf("%c", *tmp);
                    if(st->length != 0)
                    {
                        GetTop(st, (void**)&tmp);
                    }

                }

            }

            PushStack(st, &p[i]);
        }

        else if(isright(p[i]))
        {
            char* tmp2;
            GetTop(st, (void**)&tmp2);
            while(!isleft(*tmp2) && st->length)
            {
                PopStack(st, (void**)&tmp2);
                printf("%c", *tmp2);
                GetTop(st, (void**)&tmp2);
            }

            if(st->length)
            {
                PopStack(st, (void**)&tmp2);
            }

        }
        i++;
    }

    while(st->length)
    {
        char* tmp1;
        PopStack(st, (void**)&tmp1);
        printf("%c", *tmp1);
    }

}

/*后缀表达式计算规则：
遍历后缀表达式中的数字和符号：
        对于数字：进栈
        对于符号：从栈中弹出右操作数
                  从栈中弹出左操作数
                  根据符号进行运算
                  将运算结果压入栈中
遍历结束，栈中的唯一数字作为运算结果
*/

void counter(LinkStack* st, char* p)
{
    int i = 0;
    int num = 0;
    //char result;
    while(p[i] != '\0')
    {
        if(isnumber(p[i]))
        {
            int ret = p[i] - '0';
            PushStack(st, (void*)&ret);
            printf("length = %d\n", st->length);
            int* swap;
            PopStack(st, (void**)&swap);
            printf("swap = %d\n", *swap);
        }
        else if(isoperator(p[i]) && st->length != 0)
        {
            int* left;
            int* right;
            /*int* swap;
            printf("length = %d\n", st->length);
            GetTop(st, (void**)&swap);
            printf("swap = %d\n", *swap);*/
            PopStack(st, (void**)&right);
            printf("length = %d\n", st->length);
            printf("right = %d\n", *right);

            /*GetTop(st, (void**)&swap);
            printf("swap = %d\n", *swap);*/

            PopStack(st, (void**)&left);
            printf("left = %d\n", *left);
            PopStack(st, (void**)&left);
            printf("length = %d\n", st->length);
            printf("left = %d\n", *left);
            int num1, num2;
            num1 = *left;
            num2 = *right;

            //int num = 0;
            switch(p[i])
            {
            case '+':
                num = num1 + num2;
                break;
            case '-':
                num = num1 - num2;
                break;
            case '*':
                num = num1 * num2;
                break;
            case '/':
                num = num1 / num2;
                break;
            default:
                break;
            }
            //int num = num1 - num2;
            //result = num + '0';
            PushStack(st, (void*)&num);
            /*int* swap;
            GetTop(st, (void**)&swap);
            printf("swap = %d\n", *swap);
            printf("length = %d\n", st->length);*/
        }
        i++;
    }

    int* tmp;
    PopStack(st, (void**)&tmp);
    printf("Result is %d\n", *tmp);

}

