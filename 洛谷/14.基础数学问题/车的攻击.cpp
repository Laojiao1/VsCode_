// 水题
// https://www.luogu.com.cn/record/77485966
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll n, k;
ll x[N], y[N];
ll h = 0, l = 0;
int main() {
    freopen("in.in", "r", stdin);
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= k; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    sort(x+1, x+1+k);
    sort(y+1, y+1+k);
    for(ll i = 1; i <= k; i++) {
        if(x[i] != x[i+1]) h++;
        if(y[i] != y[i+1]) l++;
    }
    printf("%lld\n", n*n-(n-h)*(n-l));
    return 0;
}
