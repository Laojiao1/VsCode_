// 01背包变形
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int win[maxn], lose[maxn], use[maxn], f[maxn];
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", lose+i, win+i, use+i);
    }
    for(int i = 1; i <= n; i++) {
        for(int l = x; l >= use[i]; l--)
            f[l] = max(f[l]+lose[i], f[l-use[i]]+win[i]);
        for(int l = use[i]-1; l >= 0; l--) {
            f[l] += lose[i];
        }
    }
    printf("%lld", 5ll*f[x]);
    return 0;
}