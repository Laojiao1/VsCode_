// 水题
// 用前缀和+一点点推导
// https://www.luogu.com.cn/problem/P1147
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+2;
ll n;
ll sum[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + i;
    }
    for(int i = 1; i <= n; i++) {
        ll b = sum[i-1] + n;
        ll pos = lower_bound(sum, sum+n+1, b) - sum;
        if(sum[pos] - sum[i-1] == n) {
            if(i != pos) {
                cout << i << " " << pos << endl;
            }
        }
    }
    return 0;
}