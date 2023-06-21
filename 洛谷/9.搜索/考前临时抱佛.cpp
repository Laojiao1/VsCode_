// 还是搜索 + 回溯 https://www.luogu.com.cn/problem/P2392
// 还可以用01背包
#include <bits/stdc++.h>
using namespace std;
int s[5];
int a[21][5];
int l, r, minn;
int ans = 0;
void search(int x, int y) { // x: 当前科目中的题号，y: 当前科目
    if(x > s[y]) {
        minn = min(minn, max(l, r));
        return;
    } else {
        l += a[x][y];
        search(x+1, y);
        l -= a[x][y];

        r += a[x][y];
        search(x+1, y);
        r -= a[x][y];
    }
}
int main() {
    for(int i = 1; i <= 4; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= s[i]; j++) {
            cin >> a[j][i];
        }
    }
    for(int i = 1; i <= 4; i++) {
        minn = 1 << 30;
        search(1, i);
        ans += minn;
    }
    cout << ans << endl;
    return 0;
}