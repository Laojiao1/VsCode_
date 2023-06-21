// P1106 https://www.luogu.com.cn/problem/P1106
// 贪心 + 高精度 + 思维
// 依次遍历找到减区间然后删除当前数
#include <bits/stdc++.h>
using namespace std;
string s;
int n, a[300];
int main() {
    cin >> s >> n;
    int len = s.length();
    for(int i = 0, j = 1; i < len; i++, j++) {
        a[j] = s[i] - '0';
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= len; j++) {
            if(a[j] > a[j+1]) { // 找到减区间
                for(int k = j; k <= len; k++) { // 删除此数
                    a[k] = a[k+1];
                }
                len--; // 长度减一
                break;
            }
        }
    }
    // 去除前导0
    int i = 1;
    int pos = 1;
    while(a[i] == 0 && pos < len) {
        i++;
        pos++;
    }
    for(int i = pos; i <= len; i++) {
        cout << a[i];
    }
    return 0;
}