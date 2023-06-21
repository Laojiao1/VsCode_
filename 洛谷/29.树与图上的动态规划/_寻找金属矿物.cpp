// http://acm.hdu.edu.cn/showproblem.php?pid=4003
// 好题, 树上背包DP
// f[u][j] 表示以u为根节点，用j个机器人遍历所有点所花费的最小值
// f[u][j] = min(f[u][j], f[u][j-k] + f[v][k] + (k == 0 ? 2*len : k*len));
#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
int n, s, m;
int f[N][60], head[N], cnt;
struct Node {
	int to;
	int w; 
	int next;
} e[N << 1];
void add(int x, int y, int z) {
	e[++cnt].to = y;
	e[cnt].w = z;
	e[cnt].next = head[x];
	head[x] = cnt;
}
void dfs(int u, int father) {
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == father) continue;
		dfs(v, u);
		int len = e[i].w;
		for(int j = m; j >= 0; j--) {
			int sum = 0x3f3f3f3f;
			for(int k = 0; k <= j; k++) {
				int temp = (k == 0 ? 2*len : k * len);
				sum = min(sum, f[u][j-k] + f[v][k] + temp);
			}
			f[u][j] = sum;
		}
	}
}
int main() {
	while(~scanf("%d %d %d", &n, &s, &m)) {
		memset(f, 0, sizeof(f));
		memset(head, 0, sizeof(head));
		cnt = 0;
		for(int i = 1; i < n; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			add(a, b, w);
			add(b, a, w);
		}
		dfs(s, 0);
		cout << f[s][m] << endl;
	}
	return 0;
}