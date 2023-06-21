// 找规律：若 Cnm = x, 则x在杨辉三角中第一次出现的位置 = (1 + 2 + ... + n) + m + 1;
// 二分查找满足条件的n、m
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
typedef long long ll;
long long n; 
ll C(ll q, ll x) {
    ll ans = 1;
    for(int i = 1, j = q-x+1; i <= x; i++, j++) {
        ans = ans * j / i;
        if(ans > n) return ans;
    }
    return ans;
}
bool check(long long m) {
    long long l = 2*m, r = n, q;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        q = C(mid, m);
        if(q > n) {
            r = mid - 1;
        } else if (q < n) {
            l = mid + 1;
        } else {
            cout << (1+mid)*mid/2 + m + 1 << endl;
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n;
    for(int i = 14; i >= 0; i--) {
        if(check(i)) break;
    }
    return 0;
}
