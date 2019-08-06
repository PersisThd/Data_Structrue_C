#include <stdio.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode* lChild;
    struct BiTNode* rChild;
}BiTNode;

void PreOrderTraverse(BiTNode*);
void InorderTraverse(BiTNode*);
void PostOrderTraverse(BiTNode*);
BiTNode* CreateTree();
void NumOfLeafNode(BiTNode*, int*);
int GetHight(BiTNode*);
BiTNode* CopyTree(BiTNode*);
void DestroyTree(BiTNode*);

