// P1873 https://www.luogu.com.cn/problem/P1873
// 二分经典例题
// 找出所有树中最大的那个树的高度，然后二分枚举答案，满足条件的输出
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
int n, m, maxx = -1;
bool check(int x) {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > x) {
            sum += (long long)(a[i]- x);
        }
    }
    return sum >= m;
}
int find() {
    int l = 1, r = maxx + 1; // 可以取maxx, 所以要+1
    while(l + 1 < r) { // 小细节，两个点不能相邻，因此要l+1
        int mid = (l+r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    cout << find() << endl;
    return 0;
}