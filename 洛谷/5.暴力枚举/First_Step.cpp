// P3654
// 水题, 注意特判就行
#include <bits/stdc++.h>
using namespace std;
int r, c, k;
char mp[101][101];
long long ans = 0;
int main() {
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> mp[i][j];
        }
    }
    bool f = 1;
    for(int i = 1; i <= r; i++) { // 横向搜索
        for(int j = 1; j <= c; j++) {
            f = 1;
            for(int s = 0; s < k; s++) { //开始枚举
                if(mp[i+s][j] != '.') {
                    f = 0;
                    break;
                }
            }
            if(f == 1) ans++;
        }
    }
    for(int i = 1; i <= r; i++) { // 纵向搜索
        for(int j = 1; j <= c; j++) {
            f = 1;
            for(int s = 0; s < k; s++) {
                if(mp[i][j+s] != '.') {
                    f = 0;
                    break;
                }
            }
            if(f == 1) ans++;
        }
    }
    // 特判 如果是1的话在搜索的时候多加了一倍
    if(k == 1) {
        cout << ans/2 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}