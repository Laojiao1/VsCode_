// 水题，简单的模拟
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.in", "r", stdin);
	int n, minN = 2147483647, maxN = -2147483647;
	cin >> n;
	string unlocked, locked;
	int in, out;
	for(int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		in = h1 * 3600 + m1 * 60 + s1;
		out = h2 * 3600 + m2 * 60 + s2;
		if(in < minN) {
			minN = in;
			unlocked = t;
		}
		if(out > maxN) {
			maxN = out;
			locked = t;
		}
	}
	cout << unlocked << " " << locked;
	return 0;
}