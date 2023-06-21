#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int d1 = c - a;
        int d2 = d - b;
        if((d2 - d1) < 0 || d2 < 0) {
            cout << -1 << endl;
        } else {
            cout << 2*d2 - d1 << endl;
        }
    }
    return 0;
}