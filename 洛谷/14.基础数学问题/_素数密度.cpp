#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
typedef long long ll;
#define re register
ll l, r;
int prime[N], cnt, ans;
bool vis[N];
inline void func() {
    for(re int i = 2; i <= 50000; i++) {
        if(!vis[i]) prime[++cnt] = i;
        for(re int j = 1; i * prime[j] <= 50000; j++) {
            vis[i * prime[i]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> l >> r;
    if(l == 1) {
        l = 2;
    }
    func(); // 筛选出根号R内所有质数以及剩下的合数
    memset(vis, 0, sizeof(vis));
    for(re int i = 1; i <= cnt; i++) {
        ll p = prime[i];
        ll start = (l + p - 1) / p * p; // 从能被p整除的最小的数开始遍历
        if(start > 2 * p) { // 特判一下, 防止筛掉自己
            start = (l + p - 1) / p * p;
        } else {
            start = 2 * p;
        }
        for(re int j = start; j <= r; j += p) {
            vis[j-l+1] = 1; // 为了防止数组越界，从j-l+1开始标记
        }
    }
    for(re int i = 1; i <= r-l+1; i++) {
        if(!vis[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}