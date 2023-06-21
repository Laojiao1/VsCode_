#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int cnt[N];
int main() {
 //   freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            cnt[num]++;
        }        
        if(cnt[0] <= (n+1)/2) {
            cout << 0 << endl;
            continue;
        }
        if(cnt[0] + cnt[1] < n) {
            cout << 1 << endl;
            continue;
        }
        if(cnt[0] + cnt[1] == 0) {
            cout << 2 << endl;
            continue;
        }
        if(cnt[1] == 0) {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}