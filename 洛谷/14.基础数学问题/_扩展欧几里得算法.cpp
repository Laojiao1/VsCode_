// 求ax + by = c 的一组整数解
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a/b * y1;
    return d;
}
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c;
    int d = exgcd(a, b, x, y);
    if(c % d == 0) {
        cout << c / d * x << " " << c / d * y << endl;
    } else {
        cout << "None" << endl;
    }
    return 0;
}