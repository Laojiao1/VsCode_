#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	long long n, sum = 0;
	cin >> n;
	long long a[1005], b[1005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum << endl;
	return 0;
}