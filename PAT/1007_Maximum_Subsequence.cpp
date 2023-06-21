// 动态规划
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int main() {
	int n, v[N], l = 0, r, sum = -1, temp = 0, index = 0;
	cin >> n;
    r = n-1;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		temp += v[i];
		if(temp < 0) {
			temp = 0; // 如果小于0, 就重新开始, 同时更新左边的坐标 
			index = i + 1;
		} else if(temp > sum) { // 否则不断更新sum 
			sum = temp; 
			l = index;
			r = i;
		}
	}
	if(sum < 0) sum = 0;
	cout << sum << " " << v[l] << " " << v[r] << endl;
	return 0;
}