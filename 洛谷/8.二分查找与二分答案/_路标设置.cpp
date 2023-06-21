// 还是二分答案emm 但这是一道绿题
// https://www.luogu.com.cn/problem/P3853
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], L, n, k;
bool pd(int x) {
	int cnt = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i]-a[i-1] >= x) {
			cnt += (a[i]-a[i-1]) / x;
			if((a[i]-a[i-1]) % x == 0) 
				cnt--;
		}
	}
	if(cnt > k) return true;
	else return false;
}
int main() {
	cin >> L >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = L;
	while(l+1 < r) {
		int mid = l + ((r-l) >> 1);
		if(pd(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << r << endl;
	return 0;
} 