// https://www.bilibili.com/video/BV1id4y137ak
// https://www.luogu.com.cn/problem/P1962
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
struct matrix {
    ll c[3][3];
    matrix() {
        memset(c, 0, sizeof(c));
    }
} F, A;
ll n;
matrix operator*(matrix& x, matrix& y) {
    matrix t;
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            for(int k = 1; k <= 2; k++) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
            }
        }
    }
    return t;
}
void quickpow(ll n) {
    F.c[1][1] = F.c[1][2] = 1;
    A.c[1][1] = A.c[1][2] = A.c[2][1] = 1;
    while(n) {
        if(n & 1) F = F*A;
        A = A*A;
        n >>= 1;
    }
}
int main() {
    cin >> n;
    if(n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    quickpow(n-2);
    cout << F.c[1][1] << endl;
    return 0;
}