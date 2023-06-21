// https://www.luogu.com.cn/problem/P2043
// 任何一个整数都能够分解成若干个质因数相乘
#include <bits/stdc++.h>
using namespace std;
int a[10001];
int n;
void decompose(int x) {
    for(int i = 2; i * i <= x ; i++) {
        while(x % i == 0) {
            a[i]++;
            x /= i;
        }
    }
    if(x > 1) a[x]++;
}
int main() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        decompose(i);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i]) {
            cout << i << " " << a[i] << endl;
        }
    }
    return 0;
}