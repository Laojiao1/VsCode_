// https://www.luogu.com.cn/problem/P1305
// 输入一串二叉树，输出其前序遍历
// 格式：根节点，左儿子，右儿子
// 6
// abc
// bdi
// cj*
// d**
// i**
// j**
// abdicj
// 方法一：非递归算法, 直接写
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    cin >> n >> s;
    for(int i = 2; i <= n; i++) {
        string ss;
        cin >> ss;
        int x = s.find(ss[0]); // 找到这个子树的根节点在原串中的位置
        s.erase(x, 1); // 清除根节点
        s.insert(x, ss); // 加入子树
    }
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != '*') {
            cout << s[i];
        }
    }
    return 0;
}
// 方法二：递归标准算法
#include <bits/stdc++.h>
using namespace std;
int n;
struct BinNode {
    char father;
    char lchild;
    char rchild;
} tree[1001];
void pre(char root) {
    cout << root;
    if(tree[root].lchild != '*') {
        pre(tree[root].lchild);
    }
    if(tree[root].rchild != '*') {
        pre(tree[root].rchild);
    }
}
int main() {
    cin >> n;
    char c, root;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(i == 1) root = c; // 如果i == 1, 说明是根节点, 记录一下
        cin >> tree[c].lchild >> tree[c].rchild; // 继续输入当前节点的左右儿子结点
        tree[tree[c].lchild].father = tree[tree[c].rchild].father = c;
    }
    pre(root); // 从根节点开始遍历
    return 0;
}
