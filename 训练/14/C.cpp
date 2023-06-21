// 并查集
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int f[maxn], sum[maxn];
int n, m;
int find_(int x) {
    if(f[x] == x) return x;
    return f[x] = find_(f[x]);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a;
        if(a) {
            cin >> b;
            int headb = find_(b);
            for(int j = 1; j < a; j++) {
                cin >> c;
                int headc = find_(c);
                if(headc != headb) f[headc] = headb;
            }
        } else {
            continue;
        }
    }
    for(int i = 1; i <= n; i++) {
        int t = find_(i);
        sum[t]++;
    }
    for(int i = 1; i <= n; i++) {
        cout << sum[find_(i)] << " ";
    }
    cout << endl;
    return 0;
}