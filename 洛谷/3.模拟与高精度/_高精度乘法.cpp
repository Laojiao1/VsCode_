// P1303
// 高精度乘法
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50001;
int a[maxn], b[maxn], ans[maxn];
int len_a, len_b, len_ans;
string ret;
string mul(string s1, string s2) {
    len_a = s1.length();
    len_b = s2.length();
    len_ans = len_a + len_b;
    for(int i = 1, j = len_a-1; i <= len_a; i++, j--) {
        a[i] = s1[j] - '0';
    }
    for(int i = 1, j = len_b-1; i <= len_b; i++, j--) {
        b[i] = s2[j] - '0';
    }
    for(int i = 1; i <= len_a; i++) {
        for(int j = 1; j <= len_b; j++) {
            ans[i+j-1] += a[i] * b[j];
            ans[i+j] += ans[i+j-1] / 10;
            ans[i+j-1] %= 10;
        }
    }
    while(len_ans > 1 && ans[len_ans] == 0) len_ans--;//消除前导0
    while(len_ans >= 1) ret += ans[len_ans--] + '0';//倒序
    return ret; 
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << mul(s1, s2);
    return 0;
}