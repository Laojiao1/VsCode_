// https://www.luogu.com.cn/problem/P5788
// 寻找数列中第i个元素之后第一个大于ai的元素的下标
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+6;
int n, a[N], res[N];
stack<int> s;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = n; i >= 1; i--) {
		while(!s.empty() && a[s.top()] <= a[i]) {
			s.pop();
		}
		res[i] = s.empty() ? 0 : s.top();
		s.push(i);
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}