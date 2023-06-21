// https://www.luogu.com.cn/problem/P2951
// dijkstra
#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p> > q;
int n, m;
int head[N], cnt;
bool vis[N];
int ans[N];
struct Node {
    int to;
    int w;
    int next;
} e[N*2];
void add(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].w = z;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dijkstra() {
    ans[1] = 0;
    q.push(make_pair(0, 1)); // 距离，结点
    while(!q.empty()) {
        int top = q.top().second;
        q.pop();
        if(vis[top]) continue;
        vis[top] = 1;
        for(int i = head[top]; i; i = e[i].next) {
            if(ans[e[i].to] > ans[top] + e[i].w) {
                ans[e[i].to] = ans[top] + e[i].w;
                q.push(make_pair(ans[e[i].to], e[i].to));
            }
        }
    }
}

int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        ans[i] = 2147483647;
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b, 1);
        add(b, a, 1);
    }
    dijkstra();
    //dj();
    int maxi = -1, ret = 0, cnt_ = 0;
    for(int i = 1; i <= n; i++) {
        maxi = max(maxi, ans[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] == maxi) {
            cout << i << " ";
            break;
        }
    } 
    cout << maxi << " "; // 输出最远距离
    for(int i = 1; i <= n; i++) {
        if(ans[i] == maxi) {
            cnt_++;
        }
    } 
    cout << cnt_ << endl;
    return 0;
}