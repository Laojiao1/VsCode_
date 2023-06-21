// P2241
// 数学题
#include<iostream>
using namespace std;
#define ll long long
int main() {
	ll n, m;
    ll sum = 0, sum1 = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            sum += min(i, j);
            sum1 += i * j;
        }
    }
    cout << sum << " " << sum1 - sum << endl;
	return 0;
}