// 很水的模拟题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], b[maxn];
int k, x, n;
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            a[i] = b[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            cin >> k;
            for(int j = 1; j <= k; j++) {
                cin >> x;
                if(!a[i] && !b[x]) a[i] = b[x] = 1;
            }
        }
        int flag = 0;
        int i, j;
        for(i = 1; i <= n; i++) {
            if(!a[i]) {
                for(j = 1; j <= n; j++) {
                    if(!b[j]) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) {
            cout << "IMPROVE" << endl;
            cout << i << " " << j << endl;
        } else {
            cout << "OPTIMAL" << endl;
        }

    }
    return 0;
}