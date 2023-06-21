#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
    char data;
    struct Node* Lchild;
    struct Node* Rchild;
    struct Node* parent;
} BiTNode, *BiTree;
int Count = 0;
BiTree CreateBiTree() {
    char ch;
    BiTree T;
    scanf("%c", &ch);
    getchar();
    if(ch == '#') {
        T = NULL;
    } else {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->Lchild = CreateBiTree();
        T->Rchild = CreateBiTree();
    }
    return T;
}
void CountLeaf(BiTree T) {
    if(T)
    {
        if((T->Lchild == NULL) && (T->Rchild == NULL))
            Count++;//如果左右子树都为空，则为叶子节点，则叶子节点数加一
        else
        {   
            CountLeaf(T->Lchild);
            CountLeaf(T->Rchild);
        }  
    }
}
int main() {
    printf("请输入各个节点值(以节点数n+1个字符'#'结束, '#'表示空域, 字符之间以空格分开): ");
    BiTree T;
    T = CreateBiTree();
    CountLeaf(T);
    printf("叶子节点数为: %d", Count);
    return 0;
}