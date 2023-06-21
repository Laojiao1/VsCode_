// https://www.luogu.com.cn/problem/P2404
#include <bits/stdc++.h>
using namespace std;
int ans[101];
int vis[101];
int n, m;
void dfs(int num, int n, int i, int a) { 
    // num: 避免输出单独一个目标数 
    // n: 当前数，
    // i: 已经拆了多少个数，
    // a: 维持升序
    if(n == 0 && ans[1] != num) { 
        for(int k = 1; k < i; k++) {
            if(k != 1) {
                cout << "+" << ans[k];
            } else {
                cout << ans[k];
            }
        }
        cout << endl;
        return;
    } else {
        for(int j = a; j <= n; j++) {
            ans[i] = j;
            dfs(num, n - j, i + 1, j); 
        }
    }
}
int main() {
    cin >> n;
    dfs(n, n, 1, 1);
    return 0;
}