// P1601
// 高精度加法
// 把两个数倒置过来对应位数相加后再倒序输出，注意维护进制
#include <bits/stdc++.h>
using namespace std;
const int maxn = 520;
int a[maxn], b[maxn], ans[maxn];
int len_a, len_b, len_ans;
string ret;
string add(string s1, string s2) {
    len_a = s1.length();
    len_b = s2.length();
    len_ans = max(len_a, len_b);
    for(int i = len_a-1, j = 1; i >= 0; i--, j++) {
        a[j] = s1[i] - '0';
    }
    for(int i = len_b-1, j = 1; i >= 0; i--, j++) {
        b[j] = s2[i] - '0';
    } // 将数组倒置
    int t = 0; // 维护进制
    for(int i = 1; i <= len_ans; i++) {
        ans[i] = a[i] + b[i] + t;
        t = 0; // 注意重置0，并不是每一次都有进制
        if(ans[i] >= 10) {
            t = 1;
            ans[i] = ans[i] % 10;
        }
    }
    if(t == 1) {
        len_ans++;
        ans[len_ans] = 1;
    }
    while(ans[len_ans] == 0 && len_ans > 1) len_ans --; // 去除前导0
    while(len_ans >= 1) ret += ans[len_ans--] + '0';
    return ret;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2) << endl;
    return 0;
}