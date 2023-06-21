#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
bool zt[25], f[N]; // f[i]表示是否可以称出i重量, zt[i]表示是否选择i砝码，1表示选
// if(f[j] && !f[j+a[i]]) f[j+a[i]] = 1;
int n, m, a[N];
int ans, tot, ret;
void dp() {
    memset(f, 0, sizeof(f));
    ans = 0, tot = 0;
    f[0] = 1;
    for(int i = 0; i < n; i++) {
        if(!zt[i]) continue;
        for(int j = tot; j >= 0; j--) {
            if(f[j] && !f[j+a[i]]) {
                f[j+a[i]] = 1;
                ans++;
            }
        }
        tot += a[i];
    }
    ret = max(ans, ret);
}
void dfs(int cur, int now) { // 当前选到的砝码cur，已经放弃了now个砝码
    if(now > m) return;
    if(cur == n) {
        if(now == m) {
            dp();
        }
        return;
    }
    dfs(cur + 1, now); // 选当前砝码
    zt[cur] = 0; // 回溯
    dfs(cur + 1, now + 1);  // 不选当前砝码
    zt[cur] = 1; // 回溯
}
int main() {
    memset(zt, 1, sizeof(zt)); // 默认全选
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ret << endl;
    return 0;
}