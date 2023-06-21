// P1990
// 蓝桥杯原题
// 递推，非常锻炼思维能力
// https://www.luogu.com.cn/problem/P1990
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4;
const int maxn = 1e6;
int n;
int F[maxn], G[maxn];
int main() {
    cin >> n;
    // 初始化
    F[0] = 1;
    F[1] = 1;
    G[0] = 0;
    G[1] = 1;
    for(int i = 2; i <= n; i++) {
        F[i] = ((F[i-1] + F[i-2]) % mod + 2*G[i-2] % mod) % mod;
        G[i] = (F[i-1] + G[i-1]) % mod;
    }
    cout << F[n] % mod << endl;
    return 0;
}