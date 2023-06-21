// https://www.luogu.com.cn/problem/P1272
// 稍微变化点的树形DP
// f[i][j] 表示以i结点为根节点的子树，保留j个点(包括自己), 所删去边的最小值
#include <bits/stdc++.h>
using namespace std;
const int N = 155;
struct Node {
    int to;
    int next;
} e[N];
int cnt, head[N], chu[N];
int n, p, f[N][N]; 
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int dfs(int u) {
	int temp, sum = 1;
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		temp = dfs(v);
		sum += temp;
		for(int j = sum; j > 0; j--) {
			for(int k = 1; k < j; k++) {
				f[u][j] = min(f[u][j], f[u][j-k] + f[v][k] - 1);
			}
		}
	}
	return sum; // 这里返回的是以u结点为根的子树的大小（包括自己）
}
int main() {
	cin >> n >> p;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		chu[x]++; // 记录每个结点的出度
		add(x, y);
	}
	memset (f, 0x3f3f3f3f, sizeof (f));
	for(int i = 1; i <= n; i++) {
		f[i][1] = chu[i]; // 初始化
	}
	dfs(1);
	int ans = f[1][p]; 
	for(int i = 1; i <= n; i++) { // 注意答案要从每一个结点开始寻找最小值
		if(ans > f[i][p]) {
			ans = f[i][p] + 1; // 更新的时候别忘了+1，因为要砍掉上面一条边
		}
	}
	cout << ans << endl;
	return 0;
}
