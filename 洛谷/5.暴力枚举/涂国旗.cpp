// P3392 https://www.luogu.com.cn/problem/P3392
// 暴力枚举
#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0x7fffffff; // ans设置为无限大
int w[51], b[51], r[51]; // 分别表示从1-i行染成各自颜色所需的代价
string s;
inline int check(char c) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(s[i] != c) cnt++;
    }
    return cnt;
}
int main() {    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        // 开始枚举
        w[i] = w[i-1] + check('W');
        b[i] = b[i-1] + check('B');
        r[i] = r[i-1] + check('R');
    }
    for(int i = 1; i <= n-2; i++) { // 由于白色下面还有蓝色和红色，所以i（白与蓝的边界）枚举到（n-2）
        for(int j = i+1; j <= n-1; j++) {
            ans = min(ans, w[i]+b[j]-b[i]+r[n]-r[j]);
        }
    }
    cout << ans << endl;
    return 0;
}