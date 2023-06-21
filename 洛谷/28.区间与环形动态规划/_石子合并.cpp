// https://www.luogu.com.cn/problem/P1880
#include <bits/stdc++.h>
using namespace std;
const int N = 303;
int n, a[N], sum[N];
int dp1[N][N], dp2[N][N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
		dp1[i][i] = dp2[i][i] = 0;
        dp1[i][i+n-1] = dp2[i][i+n-1] = 0;
	}
	for(int i = 1; i <= n+n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	for(int len = 2; len <= n+n; len++) {
		for(int l = 1; l+len-1 <= n+n; l++) {
			int r = l+len-1;
			dp2[l][r] = 2147483647;
			for(int k = l; k < r; k++) {
				dp1[l][r] = max(dp1[l][r], dp1[l][k] + dp1[k+1][r] + sum[r] - sum[l-1]);
				dp2[l][r] = min(dp2[l][r], dp2[l][k] + dp2[k+1][r] + sum[r] - sum[l-1]);
			}
		}
	}
	int maxx = -1, minn = 2147483647;
	for(int i = 1; i <= n; i++) {
		maxx = max(maxx, dp1[i][i+n-1]);
		minn = min(minn, dp2[i][i+n-1]);
	}
	cout << minn << endl << maxx << endl;
	return 0;
}