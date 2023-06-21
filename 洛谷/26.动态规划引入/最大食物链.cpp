#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int ru[maxn], chu[maxn], f[maxn];
int n, m;
queue<int> q;
int ans;
int mp[maxn][maxn];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a][b] = 1;
        chu[a]++;
        ru[b]++;
    }
    for(int i = 1; i <= n; i++) {
        if(ru[i] == 0) {
            f[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        for(int k = 1; k <= n; k++) {
            if(mp[c][k] == 0) continue;
            ru[k] --;
            f[k] += f[c];
            f[k] %= 80112002;
            if(ru[k] == 0) {
                if(chu[k] == 0) {
                    ans += f[k];
                    ans %= 80112002;
                }
                q.push(k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}