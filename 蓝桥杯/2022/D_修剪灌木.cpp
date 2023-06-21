#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, f[N];
int main() {
    cin >> n;
    int flag = 0, temp;
    // int temp = n % 2 == 0 ? n / 2 : n / 2 + 1;
    if(n % 2 == 0) {
        temp = n / 2;
    } else {
        temp = n / 2 + 1;
        flag = 1;
    }
    for(int i = 1; i <= temp; i++) {
        f[i] = (n - i) * 2;
    }
    if(flag == 0) { // 偶数
        for(int i = 1; i <= temp; i++) {
            cout << f[i] << endl;
        }
        for(int i = temp; i >= 1; i--) {
            cout << f[i] << endl;
        }
    } else {
        for(int i = 1; i <= temp; i++) {
            cout << f[i] << endl;
        }
        for(int i = temp-1; i >= 1; i--) {
            cout << f[i] << endl;
        }
    }
    return 0;
}