// DFS + Dijkstra
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
typedef pair<int, int> Edge;
vector<Edge> mp[N];
vector<int> ed[N];
int cMax, n, m, sp;
int bike[N];
int distTo[N], vis[N];
int temp[N];// temp数组保存当前的临时路径
int path[N];
int minTake = 9999999;
int minNeed = 9999999;
void dfs(int u, int v) {
    temp[u] = v;
    if(v == 0) {
        int need = 0, total = 0;
        for(int t = sp; temp[t] != -1; t = temp[t]) {
            need = max(0, need + bike[t]);
            total += bike[t];
        }
        // 求带回的车辆数
        int take = need - total;
        // 调度车辆数少，或者调度车辆数相同但带回数更少的情况下更新答案
        if(need < minNeed) {
            minNeed = need;
            minTake = take;
            copy(temp, temp + N, path);
        } else if(need <= minNeed && take < minTake){
            minNeed = need;
            minTake = take;
            copy(temp, temp + N, path);
        }
        return;
    }
    // 从当前节点逆向遍历
    for(auto lt = ed[v].cbegin(); lt != ed[v].cend(); lt++){
        dfs(v, *lt);
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> cMax >> n >> sp >> m; // 最大容量，车站总数，问题车站索引。路径数量
    int HCMax = cMax / 2;
    // 数据处理
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        bike[i] = HCMax - t;
    }
    for(int i = 0; i < m; i++) {
        int u, v, time;
        cin >> u >> v >> time;
        mp[v].push_back(Edge(u, time));
        mp[u].push_back(Edge(v, time));
    }
    fill(distTo, distTo + n + 1, INT_MAX);
    fill(vis, vis + n + 1, false);
    distTo[0] = 0;
    for(int i = 0; i <= n; i++){
        int v = -1, d = INT_MAX;
        for(int i = 0; i <= n; i++){
            if(vis[i])continue;
            if(distTo[i] < d){
                v = i;
                d = distTo[i];
            }
        }
        if(v == -1) break;
        vis[v] = true;
        for(auto lt = mp[v].cbegin(); lt != mp[v].cend(); lt++){
            Edge e = *lt;
            int w = e.first;
            if(vis[w] == true) continue;
            if(e.second + distTo[v] < distTo[w]){
                distTo[w] = e.second + distTo[v];
                ed[w].clear();
                ed[w].push_back(v);
            }else if(e.second + distTo[v] == distTo[w]){
                ed[w].push_back(v);
            }
        }
    }
    temp[0] = -1;
    for(auto it = ed[sp].cbegin(); it != ed[sp].cend(); it++) {
        dfs(sp, *it);
    }
    printf("%d 0", minNeed);
    int a[n], len = 0;
    for(int t = sp; path[t] != -1; t = path[t]){
        a[len++] = t;
    }
    for(int i = len - 1; i >= 0; i--){
        printf("->%d", a[i]);
    }
    printf(" %d", minTake);
    return 0;
}