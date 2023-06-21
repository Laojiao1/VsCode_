// 高精度新思路!!!
// 贼快
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int a[maxn], b[maxn], c[maxn], sum[maxn];

void add(int *a, int *c) {
    int t = 0;
    for(int i = 1; i <= 1000; i++) {
        c[i] += a[i] + t;
        t = c[i] / 10;
        c[i] %= 10;
    }
}

void mul(int* a, int c) {
    int t = 0;
    for(int i = 1; i <= 1000; i++) {
        a[i] = a[i]*c + t;
        t = a[i] / 10;// 维护进制
        a[i] %= 10;
    }
}

int main() {
    int n;
    bool flag = 0;
    cin >> n;
    a[1] = 1;
    for(int i = 1; i <= n; i++) {
        mul(a, i);
        add(a, c);
    }
    for(int i = 1000; i >= 1; i--) {
        if(c[i] == 0)  continue;
        cout << c[i]; // 消除前导0
    }
    cout << endl;
    return 0;
}