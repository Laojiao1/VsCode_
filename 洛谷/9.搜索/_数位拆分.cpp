// 把正整数n分为m个不同的正整数，如 6 = 1 + 2 + 3 (n = 6, m = 3)
// 排在后面的数必须大于等于前面的数，输出所有方案。
#include <bits/stdc++.h>
using namespace std;
int ans[101];
int vis[101];
int n, m;
void dfs(int n, int i, int a) { // n: 当前数，i: 已经拆了多少个数，a: 维持升序
    if(i > m && n == 0) { // 拆了m个数并且n == 0的时候输出
        for(int k = 1; k < i; k++) {
            cout << ans[k] << " ";
        }
        cout << endl;
        return;
    } else {
        if(i <= m) {
            for(int j = a; j <= n; j++) {
                ans[i] = j;
                dfs(n - j, i + 1, j + 1);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    dfs(n, 1, 1);
    return 0;
}