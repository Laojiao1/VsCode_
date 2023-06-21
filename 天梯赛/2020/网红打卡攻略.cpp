#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, num, a[N], mp[N][N];
bool vis[N];
int check() {
    a[0] = 0;
    a[num+1] = 0;
    int cost = 0;
    memset(vis, 0, sizeof(vis));
    int tot = 0;
    for(int i = 0; i <= num; i++) {
        int u = a[i];
        int v = a[i+1];
        if(!mp[u][v] && !mp[u][v]) return -1;
        if(vis[v]) return -1;
        vis[v] = 1;
        cost += mp[u][v];
        tot++;
    }
    if(tot-1 < n) return -1;
    return cost;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y] = z;
        mp[y][x] = z;
    }
    int q;
    cin >> q;
    int cnt = 0;
    int maxx = 2e9;
    int id;
    for(int i = 1; i <= q; i++) {
        cin >> num;
        for(int j = 1; j <= num; j++) {
            cin >> a[j];
        }
        int temp = check();
        if(temp == -1) continue;
        cnt++;
        if(temp < maxx) {
            maxx = temp;
            id = i;
        }
    }
    cout << cnt << endl;
    cout << id << " " << maxx << endl;
    return 0;  
}