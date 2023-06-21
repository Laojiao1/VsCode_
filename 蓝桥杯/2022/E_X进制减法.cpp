#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const int Mod = 1000000007;
int A, B, X;
int a[N], b[N];
int func(int a, int b, int c) { // 返回a, b, c中最大的值
    return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
int main() {
    cin >> X >> A;
    long long res = 0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i = A; i >= 1; i--) {
        cin >> a[i];
    }
    cin >> B;
    for(int i = B; i >= 1; i--) {
        cin >> b[i];
    }
    for(int i = A; i > 1; i--) { // 边求边累加 防止溢出
        res = ((res + a[i] - b[i]) * func(a[i-1]+1, b[i-1]+1, 2)) % Mod;
    }
    res += a[1] - b[1];
    cout << res << endl;
    return 0;
}
