// 找缩点后入度为0的个数以及入度为0与出度为0的最大值
// https://www.luogu.com.cn/problem/P2746
#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
int head[N], head2[N],  cnt, cnt2;
int dfn[N], low[N], sd[N], color, vis[N], tim;
int n, mp[N][3], in[N], out[N];
int ans1, ans2;
stack<int> s;
struct Node {
	int to;
	int from;
	int next;
} e[N], e2[N];
void add(int x, int y) {
    e[++cnt].next = head[x];
    e[cnt].to = y;
    e[cnt].from = x;
    head[x] = cnt;
}
void tarjan(int now) {
	low[now] = dfn[now] = ++tim;
	s.push(now);
	vis[now] = 1;
	for(int i = head[now]; i; i = e[i].next) {
		int v = e[i].to;
		if(!dfn[v]) {
			tarjan(v);
			low[now] = min(low[now], low[v]);
		} else if(vis[v]) {
			low[now] = min(low[now], low[v]);
		}
	}
	if(dfn[now] == low[now]) {
		int y;
		++color;
		do {
			y = s.top();
			s.pop();
			vis[y] = 0;
			sd[y] = color;
		} while(now != y);
	}
}
int main() {
	cin >> n;
	int m = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		while(a != 0) {
			m++;
			add(i, a);
			cin >> a;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= m; i++) {
		int x = sd[e[i].from], y = sd[e[i].to];
		if(x != y) {
			e2[++cnt2].next = head2[x];
			e2[cnt2].to = y;
			e2[cnt2].from = x;
			head2[x] = cnt2;
			in[y]++;
			out[x]++;
		}
	}
	for(int i = 1; i <= color; i++) {
		if(in[i] == 0) ans1++;
		if(out[i] == 0) ans2++;
	}
	if(color == 1) {
		cout << "1" << endl;
		cout << "0" << endl;
	} else {
		cout << ans1 << endl;
		cout << max(ans1, ans2) << endl;
	}
	return 0;
} 



