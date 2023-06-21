#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int main() {
    int n, a[N];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int min_d = a[2] - a[1];
    if(min_d == 0) {
        cout << n << endl;
    } else {
        for(int i = 2; i <= n; i++) {
            min_d = min(min_d, __gcd(min_d, a[i] - a[i-1]));
        }
        cout << (a[n] - a[1]) / min_d  + 1 << endl;
    }
    return 0;
}
