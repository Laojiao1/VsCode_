#include <bits/stdc++.h>
using namespace std;
int n, m, minn = 100000;
int a[1001], c[1001]; // c[N]表示每次搜索所选的饲料编号
int b[1001][1001], ans[1001];
bool func(int x) {
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= x; j++) {
            sum += b[c[j]][i];
        }
        if(sum < a[i]) return false;
    }
    return true;
}
void dfs(int cur, int t) { // cur表示当前所选种类的饲料，t表示一共选了t种饲料
    if(cur > m) {
        if(func(t)) { // 如果满足条件
            if(t < minn) {
                minn = t;
                for(int i = 1; i <= minn; i++) {
                    ans[i] = c[i]; // 复制答案
                }
            }
        }
        return;
    }
    c[t+1] = cur; // 记录所选的饲料编号
    dfs(cur+1, t+1); // 搜索
    c[t+1] = 0; // 回溯
    dfs(cur+1, t); // 不选当前饲料的情况
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; // 牛每天需要的每种维他命的最小量
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j]; // 每种饲料包含的各种维他命的量的多少
        }
    }
    dfs(1, 0);
    cout << minn << " ";
    for(int i = 1; i <= minn; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}