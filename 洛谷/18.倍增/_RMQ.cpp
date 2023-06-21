// RMQ (Range Maximum/Minimum Query)
// 问题：求某个区间的最大或者最小值
// 常见方法有：单调队列，ST表，线段树
// 本次写法是用ST表法：
// ST 表是用于解决 可重复贡献问题 的数据结构。
// https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int Max[maxn][21];
int N, M;
// 用Max[i][j]表示区间[i, i+2^j-1]的最大值
// 状态方程为 Max[i][j] = max(Max[i, j-1], Max[i+2^(j-1), j-1]);
inline int read() { // 快读，让您的代码速度更好看
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') { if(c == '-')f =- 1; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x*10 + c - '0'; c = getchar(); }
    return x * f;
}
// 预处理
void init() {
    for(int j = 1; j <= 21; j++) {
        for(int i = 1; i+(1<<j)-1 <= N; i++) {
            Max[i][j] = max(Max[i][j-1], Max[i+(1<<(j-1))][j-1]);
        }
    }
}
int Query(int l, int r) {
    // 求出j
    int j = log2(r - l + 1);
    return max(Max[l][j], Max[r-(1<<j)+1][j]); // 拆分区间求最大值
}
int main() {
    // freopen("in.in", "r", stdin);
    N = read(), M = read();
    for(int i = 1; i <= N; i++) {
        Max[i][0] = read();
    }
    for(int i = 1; i <= M; i++) {
        int l = read(), r = read();
        printf("%d\n", Query(l, r));
    }
    return 0;
}