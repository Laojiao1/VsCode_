// P1255 https://www.luogu.com.cn/problem/P1255
// 高精度加法 + 斐波那契数列(用递推写的)
#include <bits/stdc++.h>
using namespace std;
int n, ns = 1;
int a[5010], b[5010], c[5010];
void solve() {
    a[1] = 1;
    b[1] = 2;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= ns; j++) c[j] = a[j] + b[j]; // 每一位相加
        for(int j = 1; j <= ns; j++) {
            if(c[j] > 9) { // 进位
                c[j+1] += c[j] / 10;
                c[j] %= 10;
                if(j + 1 > ns) ns++; // 多留一位
            }
        }
        for(int j = 1; j <= ns; j++) a[j] = b[j];
        for(int j = 1; j <= ns; j++) b[j] = c[j];
    }
}

int main() {
    cin >> n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    if(n < 3) {
        cout << n << endl;
        exit(0);
    }
    solve();
    for(int i = ns; i > 0; i--) {
        cout << b[i];
    }
    cout << endl;
    return 0;   
}