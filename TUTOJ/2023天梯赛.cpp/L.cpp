#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m;
const int N = 2e5+10;

int h[N], e[N], ne[N], idx;

int ans[N];
int res[N];
int cnt;

void insert(int x, int y) {
	e[++idx] = y;
	ne[idx] = h[x];
	h[x] = idx;
}
 
void dfs(int x) {
	res[x] = 1;
	
	for(int i=h[x]; i; i=ne[i]) {
		if(e[i] == 1) {
			ans[cnt++] = x;
		}
		if(res[e[i]] == 0) {
			dfs(e[i]);
		}
	}
}
 
 
int main() {
	
	cin >> n >> m;
	
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		insert(a, b);
	}
	
	dfs(1);
	
	if(cnt == 0) {
		printf("so sad");
		return 0;
	}
	sort(ans, ans+cnt);
	for(int i=0; i<cnt; ++i) {
		printf("%d ", ans[i]);
	} 
	
	return 0;
}