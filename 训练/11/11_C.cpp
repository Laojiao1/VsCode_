//纯纯的并查集
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn];
int find_(int x) {
    if(x = f[x]) {
        return x;
    } else {
        return f[x] = find_(f[x]);
    }
}

void solve(int a, int b) {
    int f1 = find_(a);
    int f2 = find_(b);
    if(f1 == f2) 
        return;
    f[f1] = f2;
    return;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        solve(i, x);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(f[i] == i) ans ++;
    }
    cout << ans << endl;
    return 0;
}