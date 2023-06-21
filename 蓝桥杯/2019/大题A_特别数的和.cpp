#include <bits/stdc++.h>
using namespace std;
bool check(int n) {
    while(n) {
        int num = n % 10;
        n /= 10;
        if(num == 2 || num == 0 || num == 1 || num == 9) {
            return true;
        }
    }
    return false;
}
int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(check(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
