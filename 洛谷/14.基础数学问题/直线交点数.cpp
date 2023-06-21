// https://www.luogu.com.cn/problem/P2789
// 平面上有N条直线，且无三线共点，那么这些直线能有多少不同的交点数？
// 思路：给定你n条直线，如果其中有i条平行，其他的不平行，
// 那么交点数就是(i∗(n−i))+(n−i条直线的交点数)。
// 那么我们就可以递归求出n条直线所有可能的方案（因为n很小），然后记录方案数就行了。
#include <bits/stdc++.h>
using namespace std;
bool f[10010];// f[i]表示有可能产生i个交点的情况
long long ans = 0;
int s;
void func(int n, int sum) { // n条线，可能产生sum个交点
    if(n == 0) { // 递归出口，当n条线全部平行之后
        f[sum] = 1; // 记录方案数
    } else {
        for(int i = n; i >= 1; i--) { // 从n开始遍历有几条平行线
            func(n-i, i*(n-i) + sum);
        }
    }
}
int main() {
    int n;
    cin >> n;
    func(n, 0);
    for(int i = 0; i <= n*n; i++) {
        if(f[i]) ans++;
    }
    cout << ans << endl;
    return 0;  
}