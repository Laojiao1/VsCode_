// 进制转换
#include <bits/stdc++.h>
using namespace std;
int len = 0, a[1001];
bool check() {
    for(int i = 0; i < len / 2; i++) {
        if(a[i] != a[len-i-1]) {
            return false;
        }
    }
    return true;
}
int main() {
    //freopen("in.in", "r", stdin);
    int n, radix;
    cin >> n >> radix;
    if(n > 0) {
        while(n) {
            a[len++] = n % radix;
            n /= radix;
        }
        if(check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << a[len-1];
        for(int i = len-2; i >= 0; i--) {
            cout << " " << a[i];
        }
    }
    return 0;
}