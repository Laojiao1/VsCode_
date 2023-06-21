// 有点细节
// 动态数组
// https://www.luogu.com.cn/problem/P3613
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
    vector<int> num, w; // 用动态数组维护，防止超时
    // num:格子的编号，w:物品
    int cnt = 0; // 记录该柜子放了几次
} desk[maxn]; // 有几个柜子
int main() {
    int n, q;
    cin >> n >> q;
    while(q--) {
        int num;
        cin >> num;
        if(num == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            desk[i].cnt++; // 第i个柜子存入物品, 次数加1
            desk[i].num.push_back(j); // 第i个箱子中第j个格子
            desk[i].w.push_back(k); // 放入物品
        } else {
            int i, j;
            cin >> i >> j;
            for(int pos = desk[i].cnt - 1; pos >= 0; pos--) {
                if(desk[i].num[pos] == j) { // 匹配对应的柜子的格子
                    cout << desk[i].w[pos] << endl; // 如果匹配上了就输出
                    break;
                }
            }
        }
    }
    return 0;
}