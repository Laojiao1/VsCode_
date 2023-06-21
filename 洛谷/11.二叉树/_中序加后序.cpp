// 给出一棵二叉树的中序与后序排列。求出它的先序排列
// BADC
// BDCA
// 输出：
// ABCD
#include <bits/stdc++.h>
using namespace std;
string post, inor;
void func(string inor, string post) {
    // 递归出口
    if(post.empty()) return;

    char root = post[post.length()-1]; // 后序序列的末尾字符即为根节点
    cout << root; // 由于是先序序列，所以取出根节点后直接输出
    int pos = inor.find(root); // 在中序序列找到根节点的位置
    post.erase(post.end()-1); // 删去后序序列中的根节点

    string leftpost = post.substr(0, pos); // 在后序序列中从0处切割pos个
    string rightpost = post.substr(pos); // 在后序序列中从pos开始切割到最后

    // 同理，在中序序列中进行同样操作
    string leftinor = inor.substr(0, pos);
    string rightinor = inor.substr(pos+1); // 注意这里是pos+1处

    // 递归实现
    func(leftinor, leftpost);
    func(rightinor, rightpost);
}
int main() {
    cin >> inor >> post;
    func(inor, post);
    cout << endl;
    return 0;
}