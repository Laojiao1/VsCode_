// 经典二分 https://www.luogu.com.cn/problem/P2249
// lower_bound(first, last, value) 查找首个不小于给定值的元素的位置
// upper_bound(first, last, value) 查找首个大于给定值的元素的位置
// 以上函数如果找不到的话均返回last
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+6;
ll a[N];
ll n, m;
ll find_(int k) {
    ll temp = -1;
    ll l = 1, r = n;
    ll mid;
    while(l < r) {
        ll mid = l + ((r-l) >> 1);
        if(a[mid] >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(a[l] == k) temp = l;
    return temp;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        ll num;
        cin >> num;
        ll pos = find_(num);
        cout << pos << " ";
    }
    return 0;
}