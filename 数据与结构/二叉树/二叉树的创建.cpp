#include <bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct BiNode* BiTree;
struct BiNode {
    ElementType Data;
    BiNode *lchild;
    BiNode *rchild;
};
void CreateTree(BiTree &T) {
    char ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
    } else {
        T = new BiNode; // 申请一个堆空间, 作为全局作用域
        T->Data = ch;
        CreateTree(T->lchild); // 递归创建左右子树
        CreateTree(T->rchild);
    }
} 
// void Pre(BiTree &T) {
//     if(T) {
//         cout << T->Data;
//         Pre(T->lchild);
//         Pre(T->rchild);
//     }
// }
int main() {
    BiTree T;
    cout << "Iterates through the input in order (ending with #) to store the elements: " << endl;
    CreateTree(T);
    // 以先序遍历输入，以#结束输入
    // 验证(先序遍历输出)：
    // Pre(T);
    // cout << endl;
    // system("pause");
    return 0;
}