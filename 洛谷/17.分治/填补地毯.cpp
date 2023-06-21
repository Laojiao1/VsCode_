// 暴力求解
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n, m;
ll ans;
struct Node
{
    int v;
    int x;
} e[N];
int main() {
   // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> e[i].v >> e[i].x;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            ans += max(e[i].v, e[j].v) * abs(e[i].x - e[j].x);
        }
    }
    cout << ans << endl;
    return 0;
}

