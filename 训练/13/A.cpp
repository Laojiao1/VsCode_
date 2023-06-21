// 树的深度
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int f[maxn];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = i; j <= n && j != -1; j = f[j]) {
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}