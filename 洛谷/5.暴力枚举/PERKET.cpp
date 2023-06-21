// P2036 https://www.luogu.com.cn/problem/P2036
// 入门级别的dfs，适合拿来练手
// 和全排列问题差不多
#include <bits/stdc++.h>
using namespace std;
long long s[20], b[20];// 甜度和酸度
long long pd[20];// 记录是否查找过
long long n, ans = 1e9+9;
long long acid = 1, bitter = 0;
void dfs(int k) {
    if(k > n) {
        return;
    } // 如果超过不做操作
    else {
        for(int i = k; i <= n; i++) {
            if(!pd[i]) {
                pd[i] = 1; // 记录
                acid *= s[i];
                bitter += b[i];
                ans = min(ans, abs(acid-bitter));
                dfs(k+1);
                // 回溯
                pd[i] = 0;
                acid /= s[i];
                bitter -= b[i];
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}