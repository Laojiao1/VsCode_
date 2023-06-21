#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int head[N], cnt = 0;
bool vis[N];
int ans[N], cost[N];
int n, m, start, D;
struct Node {
	int to;
	int w;
	int cost;
	int next;
} e[N*2];
void add(int x, int y, int z, int c) {
	e[++cnt].to = y;
	e[cnt].w = z;
	e[cnt].cost = c;
	e[cnt].next = head[x];
	head[x] = cnt;
}
int main() {
    //freopen("in.in", "r", stdin);
    int ed[N];
	cin >> m >> n >> start >> D;
	fill(ans, ans + 1 + m, INT_MAX);
	ans[start] = 0;
	for(int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
		add(b, a, c, d);
	} 
	fill(ed, ed + N, -1);
	int now = start;
	while(vis[now] == 0) {
		long long minn = INT_MAX;
        if(vis[now]) continue;
        if(now == D) break;
		vis[now] = 1;
		for(int i = head[now]; i; i = e[i].next) {
			if(!vis[e[i].to] && ans[e[i].to] > ans[now] + e[i].w) {
				ans[e[i].to] = ans[now] + e[i].w;
				cost[e[i].to] = cost[now] + e[i].cost;
				ed[e[i].to] = now;
			} else if(!vis[e[i].to] && ans[e[i].to] == ans[now] + e[i].w && e[i].cost + cost[now] < cost[e[i].to]) {
				ed[e[i].to] = now;
				cost[e[i].to] = cost[now] + e[i].cost;
			}
		}
		for(int i = 1; i <= m; i++) {
			if(ans[i] < minn && !vis[i]) {
				minn = ans[i];
				now = i;
			}
		}
	}
	vector<int> path;
	for(int i = D; i != -1; i = ed[i]) {
		path.push_back(i);
	}
	for(int i = (int)path.size()-1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << ans[D] << " " << cost[D] << endl;
	return 0;
}