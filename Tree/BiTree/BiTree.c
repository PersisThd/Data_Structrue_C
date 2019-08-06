#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

void PreOrderTraverse(BiTNode* T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);
}

void InorderTraverse(BiTNode* T)
{
    if(T == NULL)
    {
        return;
    }
    InorderTraverse(T->lChild);
    printf("%c", T->data);
    InorderTraverse(T->rChild);
}

void PostOrderTraverse(BiTNode* T)
{
    if(T == NULL)
        return;

    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%c", T->data);
}

//#号法创建树
BiTNode* CreateTree()
{
    char ch;
    scanf("%c", &ch);

    //递归结束条件
    if(ch == '#')
        return NULL;

    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));

    root->data = ch;
    root->lChild = CreateTree();
    root->rChild = CreateTree();

    return root;
}

//求二叉树的叶子节点数目
void NumOfLeafNode(BiTNode* T, int* n)
{
    if(T == NULL)
        return;

    NumOfLeafNode(T->lChild, n);
    NumOfLeafNode(T->rChild, n);

    if(T->lChild == NULL && T->rChild == NULL)
    {
        (*n)++;
    }
}

//求二叉树的高度
int GetHight(BiTNode* T)
{
    if(T == NULL)
        return 0;

    int h = 0;
    int left = GetHight(T->lChild);
    int right = GetHight(T->rChild);

    h = left > right ? left : right;

    return h + 1;
}

//拷贝二叉树
BiTNode* CopyTree(BiTNode* T)
{
    if(T == NULL)
        return NULL;

    BiTNode* Tnew = (BiTNode*)malloc(sizeof(BiTNode));
    Tnew->data = T->data;
    Tnew->lChild = CopyTree(T->lChild);
    Tnew->rChild = CopyTree(T->rChild);

    return Tnew;
}

//销毁二叉树
void DestroyTree(BiTNode* T)
{
    if(T == NULL)
        return;
    //必须以后序遍历的方式进行销毁，因为要保证每棵子树的根结点最后被释放
    DestroyTree(T->lChild);
    DestroyTree(T->rChild);
    printf("当前释放结点值为：%c\n", T->data);

    free(T);
}


