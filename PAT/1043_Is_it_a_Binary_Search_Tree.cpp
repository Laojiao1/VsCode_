// 二叉树
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
struct Node {
    int value;
    Node *left;
    Node *right;
    Node() : left(NULL), right(NULL){}
};
int num;
Node *root = NULL;
void insert(Node* &x, int value) {
    if(x == NULL) {
        x = new Node;
        x->value = value;
    } else if(value < x->value) {
        insert(x->left, value);
    } else {
        insert(x->right, value);
    }
}
// 或许先序遍历和后序遍历
int PreOrder[N], p = 0, mirrorPreOrder[N], q = 0;
int PostOrder[N], m = 0, mirrorPostOrder[N], n = 0;
void B_DFS(Node* &x) {
    if(x == NULL) return;
    PreOrder[p++] = x->value;
    B_DFS(x->left);
    B_DFS(x->right);
    PostOrder[m++] = x->value;
}
void M_DFS(Node* &x) {
    if(x == NULL) return;
    mirrorPreOrder[q++] = x->value;
    M_DFS(x->right);
    M_DFS(x->left);
    mirrorPostOrder[n++] = x->value;
}
// 比较两个序列是否相同
bool compare(int a[], int b[]) {
    for(int i = 0; i < N; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
// 打印序列
void print(int order[]) {
    cout << "YES" << endl;
    cout << order[0];
    for(int i = 1; i < n; i++) {
        cout << " " << order[i];
    }
}
int preOrder[N];
int main() {
    //freopen("in.in", "r", stdin);
    cin >> num;
    for(int i = 0; i < num; i++) {
        int t;
        cin >> t;
        insert(root, t);
        preOrder[i] = t;
    }
    B_DFS(root);
    M_DFS(root);
    if(compare(preOrder, PreOrder)) {
        print(PostOrder);
    } else if(compare(preOrder, mirrorPreOrder)) {
        print(mirrorPostOrder);
    } else {
        cout << "NO" << endl;
    }
    return 0;
}