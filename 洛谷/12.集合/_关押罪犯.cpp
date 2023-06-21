// https://www.luogu.com.cn/problem/P1525
// 反集
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct Node {
	int x, y, w;
};
Node f[N];
int n, m, a[N], ans = 0;
bool cmp(Node a1, Node a2) {
	return a1.w > a2.w;
}
int find(int x) {
	if(x == a[x]) return x;
	else return a[x] = find(a[x]);
}
bool check(int a, int b) {
	int c = find(a);
	int d = find(b);
	if(c == d) return true;
	else return false;
}
void add(int x, int y) {
	int c = find(x);
	int d = find(y);
	a[c] = d;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n*2; i++) a[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> f[i].x >> f[i].y >> f[i].w;
	}	
	sort(f+1, f+1+m, cmp); // 从大到小排序  
	for(int i = 1; i <= m; i++) {
		if(check(f[i].x, f[i].y)) {
			ans = f[i].w;
			break;
		} else {
			add(f[i].x + n, f[i].y); // 反集合并
			add(f[i].y + n, f[i].x);
		}
	}
	cout << ans << endl;
	return 0;
}