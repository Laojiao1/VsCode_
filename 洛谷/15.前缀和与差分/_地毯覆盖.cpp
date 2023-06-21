// https://www.luogu.com.cn/problem/P3397
// 二维差分
#include <bits/stdc++.h>
using namespace std;
int mp[2000][2000];
int main() {
    //freopen("in.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    while(m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++) {
            mp[i][y1]++;
            mp[i][y2+1]--; // 差分
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            mp[i][j] += mp[i][j-1]; // 复原
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}