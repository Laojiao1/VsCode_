// 模拟。多项式相乘
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
typedef struct {
	int x; // 系数 
	double y; // 指数 
} Ploy;
int main() {
	int n, m;
	Ploy A[N], B[N], Res[N*2] = {0, 0.0};
	cin >> m;
	for(int i = 0; i < m; i++) cin >> A[i].x >> A[i].y;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> B[i].x >> B[i].y;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int temp = A[i].x + B[j].x;
			Res[temp].y += A[i].y * B[j].y;
		}
	}
	int cnt = 0;
	for(int i = 2000; i >= 0; i--) {
		if(Res[i].y != 0.0) {
			cnt++;
		}
	}
	cout << cnt;
	for(int i = 2000; i >= 0; i--) {
		if(Res[i].y != 0.0) {
			printf(" %d %.1f", i, Res[i].y);
		}
	}
	return 0;
} 