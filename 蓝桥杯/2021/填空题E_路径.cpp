#include <bits/stdc++.h>
using namespace std;
const int maxn = 2022;
int f[maxn][maxn];
int mp[maxn][maxn];
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    memset(mp, 0x3f, sizeof(mp));
    for(int i = 1; i <= 2021; i++) {
        for(int j = i; j <= 2021; j++) {
            if(j - i <= 21) {
                mp[i][j] = i * j/__gcd(i, j);
                mp[j][i] = i * j/__gcd(i, j);
            }
        }
    }
    for(int k = 1; k <= 2021; k++) {
        for(int i = 1; i <= 2021; i++) {
            for(int j = 1; j <= 2021; j++) {
                mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    cout << mp[1][2021] << endl;
    return 0;
}