#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
vector<int> mp[N];
bool vis[N];
int maxHeight = 0;
vector<int> depthestNodes;
set<int> points; // 使用set避免加入重复元素
void dfs(int v, int height) {
    vis[v] = 1;
    if(height > maxHeight) {
        depthestNodes.clear();
        depthestNodes.push_back(v); 
        maxHeight = height;
    } else if(height == maxHeight) {
        depthestNodes.push_back(v);
    }
    for(auto it = mp[v].cbegin(); it != mp[v].cend(); it++) {
        if(vis[*it] == false) {
            dfs(*it, height + 1);
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    int n, u, v;
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        mp[v].push_back(u);
        mp[u].push_back(v);
    }
    fill(vis, vis+N, false);
    int cnt = 0;
    int s = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            dfs(i, 1);
            cnt++;
        }
    }
    // 如果连通块数量大于1就Error
    if(cnt > 1) {
        cout << "Error: " << cnt << " components" << endl;
    } else { // 否则再次进行dfs
        // 清空数据
        fill(vis, vis+N, false);
        maxHeight = 0;
        // 将depthestNodes的第一个结点作为第二次dfs的起点（其实在depthestNodes任取一个都可以）
        // 为了重用depthestNodes，先将其中的所有元素加入到points中保存
        for(auto it = depthestNodes.cbegin(); it != depthestNodes.cend(); it++) {
            points.insert(*it);
        }
        s = depthestNodes[0];
        // 第二次遍历
        depthestNodes.clear();
        dfs(s, 1);
        for(auto it = depthestNodes.cbegin(); it != depthestNodes.cend(); it++) {
            points.insert(*it);
        }
        for(auto it = points.cbegin(); it != points.cend(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}