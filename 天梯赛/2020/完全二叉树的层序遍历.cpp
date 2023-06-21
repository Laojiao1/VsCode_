#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], n, tree[N];
int cnt = 0;
void dfs(int u) {
    if(u > n)return;
    int l = 2*u;
    int r = 2*u+1;
    dfs(l);
    dfs(r);
    cout << u << " " << cnt << endl;
    tree[u] = a[++cnt];
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(i != 1) cout << " " << tree[i];
        else cout << tree[i];
    }
    return 0;
}