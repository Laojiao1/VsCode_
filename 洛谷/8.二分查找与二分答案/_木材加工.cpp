// 二分枚举找最合适的 https://www.luogu.com.cn/problem/P2440
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000007];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e8 + 1;
    int mid;
    sort(a+1, a+1+n);
    while(l + 1 < r) { // l和r不能相邻, 留出 mid
        int cnt = 0;
        mid = l + ((r - l) >> 1);
        for(int i = 1; i <= n; i++) {
            cnt += a[i] / mid;
        }
        if(cnt >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl; // 答案是l，因为可能最后一次的时候m不满足要求，
                       // 这时候只能输出在上一次满足要求时记录下答案的l。
    return 0;
}