// https://www.luogu.com.cn/problem/P1102
// 水题
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
typedef long long ll;
ll n, c, cnt = 0;
ll a[N];
map<ll, ll> b; // 这里要开个map，不然会爆
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] ++;
        a[i] -= c;
    }
    for(int i = 1; i <= n; i++) {
        cnt += b[a[i]];
    }
    cout << cnt << endl;
    return 0;
}