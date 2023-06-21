// https://www.luogu.com.cn/problem/P3390
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
struct matrix {
    ll c[101][101];
    matrix() {
        memset(c, 0, sizeof(c));
    }
} a, res;
ll n, k;
matrix operator*(matrix &x, matrix& y) {
    matrix t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % Mod;   
            }
        }
    }
    return t;
}
void quickpow(ll k) {
    for(int i = 1; i <= n; i++) {
        res.c[i][i] = 1;
    }
    while(k) {
        if(k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a.c[i][j];
        }
    }
    quickpow(k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << res.c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}