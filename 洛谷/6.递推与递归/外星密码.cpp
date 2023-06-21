// P1928 https://www.luogu.com.cn/problem/P1928
// 简单的递归题，适合拿来练手
#include <bits/stdc++.h>
using namespace std;
string solve() {
    int n;
    string s = "";
    string s1;
    char c;
    while(cin >> c) { // 不断输入字符，直到ctrl+z
        if(c == '[') {
            cin >> n;
            s1 = solve();
            while(n--) {
                s += s1;
            }
        } else {
            if(c == ']') return s;
            else s += c;
        }
    }
}
int main() {
    cout << solve() << endl;
    return 0;
}