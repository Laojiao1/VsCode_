// P1217
#include<bits/stdc++.h>
using namespace std;
bool solve(int n) {
	if(n == 1)
		return 0;
	if(n % 2 == 0) {
		return 0;
	} else {
		int i;
		for(i = 2; i <= sqrt(n); i++) {
			if(n % i == 0)
				return 0;
		}
		return 1;
	}
}
bool solve2(int n) {
	int sum = 0;
	int k = n;
	while(n) {
		sum = sum * 10 + n % 10;
		n /= 10;
	} // 回文质数判断的优化代码
	if(sum == k)
		return 1;
	else
		return 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = n; i <= m; i++) {
		if(i == 9989900) //如果到了这个数，就break 
			break;
		if(solve2(i) && solve(i)) 
			cout << i << endl;
	}
	return 0;
}