// 组合数学
// https://www.luogu.com.cn/problem/P3799
// 桶排序
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n;
int a[100001];
int bus[5005];
int ans, maxlen = -1;
int func(int k) {
    return ((k * k - k) / 2) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxlen = max(maxlen, a[i]);
        bus[a[i]] ++;
    }
    for(int i = 0; i <= maxlen; i++) {
        for(int j = i; j <= maxlen; j++) {
            if(i + j > 5000) break; // 根据条件范围，防止超时
            if(bus[i+j] > 0) {
                if(i == j) {
                    ans = (ans + func(bus[i])*func(bus[i+i])) % mod;
                } else {
                    ans = (ans + (((bus[i]*bus[j])%mod)*func(bus[i+j]))% mod) % mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}