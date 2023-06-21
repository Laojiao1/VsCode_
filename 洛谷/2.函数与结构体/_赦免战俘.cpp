// 不进位加法，可以用^（异或）运算符
// 1 ^ 1 = 0
// 1 ^ 0 = 1
// 0 ^ 1 = 1
// 0 ^ 0 = 1
// 相同为0 不同为1
#include <bits/stdc++.h>
using namespace std;
long long a[1 << 10+1][1 << 10+1];
int main() {
    int m;
    cin >> m;
    long long n = pow(2, m);
    for(int i = 1; i <= n; i++) {
        a[i][i] = 1;
        a[i][1] = 1;
        a[n][i] = 1;
    }
    for(int i = 3; i < n; i++) {
        for(int j = 2; j < i; j++) {
            a[i][j] = a[i-1][j] ^ a[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= 1; j--) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}