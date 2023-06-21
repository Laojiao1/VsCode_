// 水题
#include<bits/stdc++.h>
using namespace std;
int W, ans = 0;
int n, a[30001];
int i;
int main() {
    scanf("%d %d",&W, &n);
    for(i = 1;i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int l = 1, r = n;
    while(l <= r)
    {
        if(a[l] + a[r] <= W) {
            l++;
            r--;
            ans++;
        }
        else {
            r--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}