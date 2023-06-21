// 优先队列
// 给定一个长度为n的整数序列，请找出长度不超过k的连续子序列最大和
// 例如：
// 7 3
// 2 -3 5 2 -4 -1 8
// 输出：
// 8
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
typedef pair<int, int> a;
priority_queue<a, vector<a>, greater<a> > q;
int n, k, arr[N], ans = -1;
int sum[N];
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
	int temp = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			q.push(make_pair(sum[i], i));
			if(j-k >= 0) {
				while(q.top().second <= j-k) {
					q.pop();
				}
				temp = q.top().first;
				cout << temp << " ";
			}
		}
		cout << endl;
		ans = max(ans, sum[i] - temp);
	}
	cout << ans << endl;
	return 0;
} 
