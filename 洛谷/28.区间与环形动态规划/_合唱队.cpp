// https://www.luogu.com.cn/problem/P3205
// 每人进入队伍里，只有2种可能，1种是从左边加入，另外1种是从右边进入
// f[i][j][0]表示的是在区间i~j中第i人从左边进来的方案数
// f[i][j][1]表示的是在区间i~j中第j人从右边进来的方案数
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, f[N][N][2], a[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) f[i][i][0] = 1;
	for(int len = 2; len <= n; len++) {
		for(int l = 1; l+len-1 <= n; l++) {
			int r = l+len-1;
			if(a[l+1] > a[l]) f[l][r][0] += f[l+1][r][0];
			if(a[r] > a[r-1]) f[l][r][1] += f[l][r-1][1];
			if(a[l] < a[r]) f[l][r][0] += f[l+1][r][1];
			if(a[l] < a[r]) f[l][r][1] += f[l][r-1][0];
			f[l][r][0]%=19650827;
			f[l][r][1]%=19650827;
		}
	}
	cout << (f[1][n][0] + f[1][n][1])%19650827 << endl;
	return 0;
}