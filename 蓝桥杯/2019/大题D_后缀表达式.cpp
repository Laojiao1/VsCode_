#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, a[N];
int cnt1 = 0, cnt2 = 0;
int ans = 0;
void sum(bool num) {
    if(num == 1) {
        for(int i = 1; i <= n+m+1; ++i) {
            ans += a[i];
        }
    } else {
        for(int i = 1; i <= n+m+1; ++i) {
            ans += abs(a[i]);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n+m+1; i++) {
        cin >> a[i];
        if(a[i] >= 0) {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    /*
        如果负号个数等于为0，直接求总和
        如果负号个数不为0：
        0. 如果没有负数，总和-最小正数
        1. 如果负数个数等于总元素个数，那么一定剩下一个负数，答案就是所有数的绝对值的总和-负数最大的那个(绝对值最小的那个)
        2. 如果负数个数不等于总元素个数，答案为所有数的绝对值之和(可以通过加括号方式把负数变为正数)
    */
    sort(a+1, a+1+n+m);
    if(m == 0) {
        sum(1);
    } else {
        if(cnt2 == 0) {
            sum(1);
            ans -= 2*a[cnt2+1];
        } else {
            if(cnt2 == n+m+1) {
                sum(0);
                ans -= 2*a[cnt2];
            } else {
                sum(0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
