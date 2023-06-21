#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
#define debug(a) cout << #a << " = " << a << endl;
using namespace std;
typedef long long ll;
int n, m;
struct node {
	int t, l, r;
}a[110];
bool cmp(node x, node y) {
    return x.t < y.t;
}
int main(void)
{
	//freopen("in.in", "r", stdin);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)cin >> a[i].t >> a[i].l >> a[i].r;
		bool flag = true;
		int l = m, r = m;
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; ++i) {
			int d = a[i].t - a[i - 1].t;
			l -= d; r += d;
			l = max(l, a[i].l); r = min(r, a[i].r);
			if (l > r) {   //严格l>r
				flag = false;
				break;
			}
		}
		if (flag)puts("YES");
		else puts("NO");
	}
	return 0;
}