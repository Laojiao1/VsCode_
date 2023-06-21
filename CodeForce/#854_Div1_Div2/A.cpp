#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5e4 + 5, p = 1e9 + 7;
int a[N];
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) a[i] = -1;
	set<int> st;
	int p = n;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (!st.count(x) && p) {
			a[p--] = i;//记录弹出时间
			st.insert(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve(); 
}
