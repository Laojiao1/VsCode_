// DFS 求每一辈的叶子节点个数
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
vector<int> children[N];
int maxFloor = 0, ans[N];
void dfs(int p, int floor) {
	maxFloor = max(floor, maxFloor);
	int l = children[p].size();
	if(l == 0) {
		ans[floor]++;
		return;
	} else {
		//floor++;
		for(int i = 0; i < l; i++) {
			dfs(children[p][i], floor+1);
		}
	}
}
int main() {
	int n, m, id, k, child;
	cin >> n >> m;
	while(m-- > 0) {
		cin >> id >> k;
		while(k-- > 0) {
			cin >> child;
			children[id].push_back(child);
		}
	}
	dfs(1, 0);
	cout << ans[0];
	for(int i = 1; i <= maxFloor; i++) {
		cout << " " << ans[i];
	}
	return 0;
}