#include <bits/stdc++.h>
using namespace std;
int ans;
int n, m;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            ans += a;
        }
        ans *= 2;
        if(n == 2 || m < n) { //一定无解
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
        for(int i = 1; i < n; i++) {
            cout << i+1 << " " << i << endl;
        }
        cout << n << " " << 1 << endl;;
    }
    return 0;
}