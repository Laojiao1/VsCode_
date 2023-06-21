// 模拟
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N], b[N];
int main() {
    //freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < N; i++) a[i] = 0;
        for(int i = 0; i < N; i++) b[i] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        bool ans = true;
        for(int i = 1; i <= n; i++) {
            if((a[i] <= a[n] && b[i] <= b[n]) || (b[i] <= a[n] && a[i] <= b[n])) {
                continue;
            } else {
                ans = false;
                break;
            }
        } 
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}