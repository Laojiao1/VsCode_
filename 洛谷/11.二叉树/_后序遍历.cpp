// 输入一串二叉树，输出其后序遍历
// 格式：根节点，左儿子，右儿子
// 6
// abc
// bdi
// cj*
// d**
// i**
// j**
// dibjca
#include <bits/stdc++.h>
using namespace std;
int n; // 结点数
struct BinNode {
    char father;
    char lchild;
    char rchild;
} tree[1001];
void inor(char root) {
    if(tree[root].lchild != '*') inor(tree[root].lchild);
    if(tree[root].rchild != '*') inor(tree[root].rchild);
    cout << root;
}
int main() {
    cin >> n;
    char c, root;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(i == 1) root = c;
        cin >> tree[c].lchild >> tree[c].rchild;
        tree[tree[c].lchild].father = tree[tree[c].rchild].father = c;
    }
    inor(root);
    return 0;
}