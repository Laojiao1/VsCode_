// https://www.luogu.com.cn/problem/P2822
// 杨辉三角和组合数之间的关系，前缀和
// C(n m) = C(n-1 m-1) + C(n-1 m)
// 杨辉三角中：第n行的m个数可表示为 C(n-1，m-1)，即为从n-1个不同元素中取m-1个元素的组合数。
// 所以在这道题里面，完全可以通过杨辉三角把需要用到的组合数给算出来，
// %k判一下存到数组 f[i][j] 里，若 f[i][j]==0,则计数器ans+1。最后输出ans的值就好啦。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, dp[2002][2002]; // dp[n][m]表示满足题意的结果数量
int k, f[2002][2002];
void func() {
	f[0][0] = f[1][0] = f[1][1] = 1; // 初始化
	for(int i = 2; i <= 2000; i++) {
		f[i][0] = f[i][i] = 1;
		for(int j = 1; j <= i; j++) {
			f[i][j] = (f[i-1][j-1] % k + f[i-1][j] % k) % k; // 把满足题意的筛选出来
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]; // 二位前缀和进行优化计算
			if (f[i][j] == 0) dp[i][j]++;
		}
		dp[i][i+1] = dp[i][i]; // 注意这里
	}
}
int main() {
    freopen("in.in", "r", stdin);
	scanf("%lld %d", &t, &k);
	func();
	while(t--) {
		int m, n;
		scanf("%d %d", &n, &m);
		if(m > n) printf("%lld\n", dp[n][n]);
		else printf("%lld\n", dp[n][m]);
	}
	return 0;
}