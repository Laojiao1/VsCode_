// https://www.luogu.com.cn/problem/P1246
// 组合数
#include <bits/stdc++.h>
using namespace std;
string s;
int ans, len;
int func(int n, int m) { // 组合数计算
    if(m == 0) return 1;
    int fz = 1;
    int fm = 1;
    for(int i = n; i >= n-m+1; i--) fz *= i;
    for(int i = 1; i <= m; i++) fm *= i;
    return fz/fm;
}
int main() {
    cin >> s;
    len = s.size();
    for(int i = 1; i < len; i++) {
        if(s[i] <= s[i-1]) {
            cout << 0 << endl; // 如果没有按照字典序就说明编码不存在
            return 0;
        }
    }
    for(int i = 1; i < len; i++) {
        ans += func(26, i);
    }
    for(int i = 0; i < len; i++) {
        for(char j = ( i == 0 ? 'a' : s[i-1]+1); j < s[i]; j++) {
            ans += func('z'-j, len-i-1);
        }
    }
    cout << ans+1 << endl;
    return 0;
}