#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 2e5+10;
int a[maxn];
int main() {
    int ans = 0;
    int n, t, m;
    cin >> n >> m;
    ans = n;
    while(m--) {
        int x, y;
        cin >> x >> y;
        a[min(x, y)]++;
        if(a[min(x,y)] == 1)
        ans--;
   }
   cin >> t;
   while(t--) {
       int x, y;
       cin >> x;
       if(x == 1) {
            cin >> x >> y;
            a[min(x ,y)]++;
            if(a[min(x,y)] == 1)
                ans--;
        } else if(x == 2) {
            cin >> x >> y;
            a[min(x, y)]--;
            if(a[min(x, y)] == 0)
            ans++;
       } else {
           cout << ans << endl;
       }
    }
    return 0;
}