// 水题
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 2;
ll n, c, cnt = 0;
ll a[N];
int main() {
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++) {
        cnt += ((upper_bound(a+1+i, a+1+n, a[i] + c) - a) - (lower_bound(a+1+i, a+1+n, a[i] + c) - a));
    }
    cout << cnt << endl;
    return 0;
}