// 埃氏筛会爆0，本题用欧拉筛
// https://www.luogu.com.cn/problem/P3383
#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+1;
int is_prime[N], Prime[N], q, n, cnt = 0;
int main() {
    // freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        is_prime[i] = 1;
    }
    is_prime[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) Prime[++cnt] = i;
        for(int j = 1; j <= cnt && i*Prime[j] <= n; j++) {
            // 每个合数只被最小的质因子筛掉
            is_prime[i*Prime[j]] = 0;
            // 1. i % Prime[j] != 0, i中的最小质因子都是比Prime[j]大的
            // 2. i % Prime[j] == 0, Prime[j]是i的最小质因子, 直接break
            if(i % Prime[j] == 0) { 
                break;
            }
        }
    }
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << Prime[x] << endl;
    }
    return 0;
}