// 尺取法
// https://www.luogu.com.cn/problem/P1638
#include <bits/stdc++.h>
using namespace std;
int n, m, ans_l, ans_r;
const int maxn = 1000005;
int a[maxn], b[maxn]; // a[]表示第i幅画的名师的编号，b[]表示以i为编号的名师的画出现的次数
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 1; // 记录出现新画师的数量
    int ans = 99999999; // 记录出现所有画师的最小区间长度
    int l, r;
    l = r = 1;
    b[a[1]] = 1; // 预处理
    while(l <= r && r <= n) { // 不能超界
        if(cnt == m) { // 如果画师全都出现了
            if(ans > r - l + 1) { // 更新区间最小值
                ans = r - l + 1;
                ans_l = l, ans_r = r;
            }
            b[a[l]]--; // 让队列头出去
            if(b[a[l]] == 0) cnt--; // 如果为0了还需要减掉一位画家
            l++; 
        } else {
            r++;
            if(b[a[r]] == 0) cnt++;
            b[a[r]]++;
        }
    }
    cout << ans_l << " " << ans_r << endl;
    return 0;
}