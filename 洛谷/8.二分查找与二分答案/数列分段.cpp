// 依旧是二分答案
#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[100001];
int l, r, mid;
inline bool pd(int k) {
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(sum + a[i] <= k) {
            sum += a[i];
        } else {
            sum = a[i];
            cnt++;
        }
    }
    if(cnt >= m) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        r += a[i];
    }
    while(l <= r) {
        mid = (l + r) >> 1;
        if(pd(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}