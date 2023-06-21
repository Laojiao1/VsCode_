#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> d[i];
	int res = 0;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			++ mp[a[i] + b[j]];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(mp.count(- c[i] - d[j]))
				res += (mp[- c[i] - d[j]]);
		}
	}
	cout << res;
	return 0;
}