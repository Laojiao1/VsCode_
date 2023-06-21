// DFS
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<int> mp[N];
bool marked[N];
void dfs(int v) {
	marked[v] = 1;
	for(auto it = mp[v].cbegin(); it != mp[v].cend(); it++) {
		if(!marked[*it]) {
			dfs(*it);
		}
	}
}
int main() {
    //freopen("in.in", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	int u, v;
	while(m-- > 0) {
		cin >> u >> v;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}
	int t;
	for(int i = 0; i < k; i++) {
		cin >> t;
		fill(marked, marked + N, false);
		marked[t] = true;
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(marked[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		cout << cnt-1 << endl;
	}
	return 0;
}