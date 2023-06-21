// https://www.luogu.com.cn/problem/P1063
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int a[N], n, f[N][N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int len = 3; len <= n+n; len++) {
		for(int l = 1; l+len-1 <= n+n; l++) {
			int r = l+len-1;
			for(int k = l+1; k < r; k++) {
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l]*a[k]*a[r]);
			}
		}
	}
	int ans = -1;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, f[i][i+n]);
	}
	cout << ans << endl;
	return 0; 
}