#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

int main()
{
    printf("请输入用于#号法创建树的字符串:\n");

    BiTNode* T;
    T = CreateTree();

    printf("\n先序遍历：\n");
    PreOrderTraverse(T);

    printf("\n中序遍历：\n");
    InorderTraverse(T);

    printf("\n后序遍历：\n");
    PostOrderTraverse(T);
    printf("\n");

    int n = 0;
    NumOfLeafNode(T, &n);
    printf("该二叉树叶子结点数目为：%d\n", n);

    int h = GetHight(T);
    printf("该二叉树的高度为：%d\n", h);

    BiTNode* T1 = CopyTree(T);
    printf("中序遍历新拷贝的二叉树：\n");
    InorderTraverse(T1);
    printf("\n");

    printf("销毁二叉树T1：\n");
    DestroyTree(T);

    return 0;
}
