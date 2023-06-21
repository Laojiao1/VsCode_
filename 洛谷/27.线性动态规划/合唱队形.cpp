// https://www.luogu.com.cn/record/77389367
// 先从1到n求一趟最长升，然后从n到1也求一趟，
// 最后枚举中间的Ti，从众多Ti中挑个大的。
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], dp1[N], dp2[N];
int ans = -1;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[j] < a[i]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
	for(int i = n; i >= 1; i--) {
		for(int j = n+1; j > i; j--) {
			if(a[j] < a[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	cout << n - ans << endl;
	return 0;
}