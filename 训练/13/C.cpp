#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int a, b;
char mp[maxn][maxn];
int main() {
    int cnt = 0;
    cin >> a >> b;
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            cin >> mp[i][j];
            if(mp[i][j] == '*')
                ++cnt;
        }
    }
    int cnt2 = 0;
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            if(mp[i][j] == '*' && mp[i + 1][j] == '*' && mp[i - 1][j] == '*' && mp[i][j + 1] == '*' && mp[i][j - 1] == '*') {
                cnt2 = cnt-1;
                for(int k = 1; i + k <= a; ++k) {
                    if(mp[i + k][j] == '.')
                        break;
                    --cnt2;
                }
                for(int k = 1; j + k <= b; ++k) {
                    if(mp[i][j + k] == '.')
                        break;
                    --cnt2;
                }
                for(int k = 1; i - k > 0; ++k) {
                    if(mp[i - k][j] == '.')
                        break;
                    --cnt2;
                }
                for(int k = 1; j - k > 0; ++k) {
                    if(mp[i][j - k] == '.')
                        break;
                    --cnt2;
                }
                if(cnt2 == 0) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

