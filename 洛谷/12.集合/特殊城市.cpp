// 水题 https://www.luogu.com.cn/problem/P3405
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n, ans;
int main() {
    cin >> n;
    while(n--) {
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2); // 取出前两个字符
        mp[b+a]++; // 记录该对应字符串已经出现
        if(a != b) { // 自己不能跟自己对应
            ans += mp[a+b];
        }
    }
    cout << ans << endl;
    return 0;
}