// 利用差分与前缀和求出每一段经过城市的次数，然后贪心选择费用最小的
// https://www.luogu.com.cn/problem/P3406
#include <bits/stdc++.h>
using namespace std;
int n, m;
int p1, p2;
int c[1000005];
long long sum, ans; // 记得开longlong
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    if(m > 0) cin >> p1;
    for(int i = 2; i <= m; i++) {
        cin >> p2;
        if(p1 < p2) {
            c[p1]++;
            c[p2]--;
        } else {
            c[p2]++;
            c[p1]--; 
        }
        p1 = p2; // 传递
    }
    for(int i = 1; i < n; i++) {
        sum += c[i];
        int A, B, C;
        cin >> A >> B >> C;
        if(sum) ans += min(A*sum, B*sum + C);
    }
    if(m <= 1) ans = 0; // 记得特判,去0和1个城市的时候不需要花钱买票
    cout << ans << endl;
    return 0;
}