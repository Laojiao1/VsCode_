#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> a;
priority_queue<a, vector<a>, greater<a> > q;
const int N = 1001;
struct Node {
    int to;
    int next;
    int w;
} e[N];
int head[N], cnt;
int n, m, p, change[N];
vector<a> v[2][N];
void add(int x, int y, int w) {
    e[++cnt].to = y;
    e[cnt].w = w;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dijkstra(int index) {
    
}
int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++) {
        int l, r, c, d;
        cin >> l >> r >> c >> d;
        v[0][l].push_back({c, r});
        v[1][r].push_back({d, l});
    }
    for(int i = 1; i <= n; i++) {
        cin >> change[i];
    }
    return 0;
}