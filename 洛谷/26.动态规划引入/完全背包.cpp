#include <bits/stdc++.h>
using namespace std;
int T, M;
const int maxn = 1e7 + 5;
int t[maxn], m[maxn];
long long f[maxn];

int main() {
    freopen("in.in", "r", stdin);
    cin >> T >> M;
    for(int i = 1; i <= M; i++) {
        cin >> t[i] >> m[i];
    }
    for(int i = 1; i <= M; i++) {
        for(int l = t[i]; l <= T; l++) {
            if(f[l - t[i]] + m[i] > f[l])
                f[l] = f[l - t[i]] + m[i];
        }
    }
    for(int i = 1; i <= T; i++) {
        cout << f[T] << " ";
    }
    //cout << f[T];
    return 0;
}