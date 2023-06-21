// https://www.luogu.com.cn/problem/P3370
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131;
const int N = 1e4+5;
ULL h[N], a[N];
int n, ans = 0;
ULL hash_(string s) {
	h[0] = 0;
	int len = s.length();
	for(int i = 1; i <= len; i++) {
		h[i] = h[i-1] * P + s[i-1];
	}
	return h[len];
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a[i] = hash_(s);
	}
	sort(a+1, a+1+n);
	for(int i = 1; i < n; i++) {
		if(a[i] != a[i+1]) {
			ans++;
		}
	}
	cout << ans+1 << endl;
	return 0;
}