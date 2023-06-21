// 给定区间[x, y], 求满足下列条件的整数的个数
// 这个数恰好等于K个互不相等的B的整数幂之和
// 命题等价于求数字n在b进制下是否由k个1且其他位全是0组成 
#include <bits/stdc++.h>
using namespace std;
const int N = 34;
int x, y, k, B;
int f[N][N], a[N];
// f[i][j]表示在i位数上放j个1的组合数 
void init() {
	for(int i = 0; i < N; i++) {
		f[i][0] = 1;
	}
	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= i; j++)
		f[i][j] = f[i-1][j-1] + f[i-1][j]; 
	}
}
int DP(int n) {
	if(!n) return 0;
	int cnt = 0;
	int res = 0, last = 0;
	while(n) {
		a[++cnt] = n % B;
		n /= B;
	}
	for(int i = cnt; i >= 1; i--) {
		int x = a[i];
		if(x == 0) continue; // 如果等于0，就跳过 
		res += f[i-1][k-last]; // 第i位放0,后面可以放k-last个1 
		if(x > 1) { // 如果x > 1 
			if(k-last-1 >= 0) res += f[i-1][k-last-1]; // 第i位放1 
			break; // 第i位放大于1的数，直接break 
		} else {  // 如果x == 1 
			last++; // 如果第i位放1，不能用组合数计算，记录1的个数，继续枚举下一位 
			if(last > k) break; // 如果1的个数大于k了，直接break; 
		}
		if(i == 1 && last == k) res++; // 特判，走到末位的情况 
	}
	return res;
} 
int main() {
	//cin >> x >> y >> n >> k;
	init();
	B = 2; // B进制 
	k = 2; // k个1 
	cout << DP(14) << endl;
	return 0;
} 