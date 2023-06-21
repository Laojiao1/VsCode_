// 深入浅出板子题
// 学习此题的存图方式
// https://www.luogu.com.cn/problem/P5318
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v;
};
vector<Edge> v;
vector<int> e[100001];// 存放具体信息
queue<int> q; // BFS必备队列
bool vis1[100001], vis2[100001];
bool cmp(Edge x, Edge y) {
    if(x.v == y.v) {
        return x.u < y.u;
    } else {
        return x.v < y.v;
    }
}
void dfs(int x) {
    vis1[x] = 1; // 标记已经访问
    cout << x << " ";
    for(int i = 0; i < e[x].size(); i++) { // 遍历当前结点的所有边
        int point = v[e[x][i]].v; 
        if(!vis1[point]) {
            dfs(point);
        }
    }
}
void bfs(int x) {
    q.push(x);
    cout << x << " ";
    vis2[x] = 1;
    while(!q.empty()) {
        int start = q.front();
        for(int i = 0; i < e[start].size(); i++) { // 遍历当前结点的所有边
            int point = v[e[start][i]].v;
            if(!vis2[point]) {
                vis2[point] = 1;
                q.push(point);
                cout << point << " ";
            }
        }
        q.pop();
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) { // m条边
        int uu, vv;
        cin >> uu >> vv;
        Edge temp;
        temp.u = uu;
        temp.v = vv;
        v.push_back(temp); // 把每个边都存入到容器中
    }
    sort(v.begin(), v.end(), cmp); // 排序
    for(int i = 0; i < m; i++) {
        e[v[i].u].push_back(i); // 在每个节点中存放与该节点连接的边
    }
    dfs(1);
    cout << endl;
    bfs(1);
    return 0;
}