// 应包括如下主要内容：
// ?	数据结构定义
// ?	算法设计思路简介
// ?	算法描述：可以用自然语言、伪代码或流程图等方式
// ?	算法的实现和测试结果：包括算法运行时的输入、输出，实验中出现的问题及解决办法等
// ?	算法时间复杂度分析
#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
    char data;
    struct Node* Lchild;
    struct Node* Rchild;
    struct Node* parent;
} BiTNode, *BiTree;
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
// 前序遍历
void PreOrder(BiTree T) {
    if(T) {
        printf("%c ", T->data);
        PreOrder(T->Lchild);
        PreOrder(T->Rchild);
    }
}
// 中序遍历
void InOrder(BiTree T) {
    if(T) {
        PreOrder(T->Lchild);
        printf("%c ", T->data);
        PreOrder(T->Rchild);
    }
}
// 后序遍历
void PostOrder(BiTree T) {
    if(T) {
        PreOrder(T->Lchild);
        PreOrder(T->Rchild);
        printf("%c ", T->data);
    }
}
int main() {
    printf("请输入各个节点值(以节点数n+1个字符'#'结束, '#'表示空域, 字符之间以空格分开): ");
    BiTree T;
    T = CreateBiTree();
    printf("前序遍历: ");
    PreOrder(T);
    putchar('\n');
    printf("中序遍历: ");
    InOrder(T);
    putchar('\n');
    printf("后序遍历: ");
    PostOrder(T);
    putchar('\n');

    return 0;
}