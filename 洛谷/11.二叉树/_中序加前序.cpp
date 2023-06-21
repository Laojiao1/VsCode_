// 中序+前序->后序
// https://www.luogu.com.cn/problem/P1827
// ABEDFCHG
// CBADEFGH 
// 输出：
// AEFDBHGC
#include <bits/stdc++.h>
using namespace std;
string pre, inor;
void func(string pre, string inor) {
    // 递归出口
    if(pre.empty()) return;

    char root = pre[0]; // 前序序列的首字母即为根节点
    int pos = inor.find(root); // 在中序序列找到根节点的位置
    pre.erase(pre.begin()); // 删去前序序列中的根节点

    string leftpre = pre.substr(0, pos); // 在前序序列中从0处切割pos个
    string rightpre = pre.substr(pos); // 在前序序列中从pos开始切割到最后

    // 同理，在中序序列中进行同样操作
    string leftinor = inor.substr(0, pos);
    string rightinor = inor.substr(pos+1); // 注意这里是pos+1处

    // 递归实现
    func(leftpre, leftinor);
    func(rightpre, rightinor);

    cout << root; 
}
int main() {
    cin >> inor >> pre;
    func(pre, inor);
    cout << endl;
    return 0;
}