// https://www.luogu.com.cn/problem/P1939
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
struct matrix {
    ll c[4][4];
    matrix() {
        memset(c, 0, sizeof(c));
    }
} F, A;
ll n, t;
matrix operator*(matrix& x, matrix& y) {
    matrix t;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
            }
        }
    }
    return t;
}
void quickpow(ll n) {
    F.c[1][1] = F.c[1][2] = F.c[1][3] = 1;
    memset(A.c, 0, sizeof(A.c)); 
    A.c[1][1] = A.c[1][2] = A.c[2][3] = A.c[3][1] = 1;
    while(n) {
        if(n & 1) F = F*A;
        A = A*A;
        n >>= 1;
    }
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n <= 3) {
            cout << 1 << endl;
            continue;
        }
        quickpow(n-3);
        cout << F.c[1][1] << endl;
    }
    return 0;
}