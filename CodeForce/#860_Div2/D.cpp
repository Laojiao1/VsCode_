// 前提条件，a1+a2+...+an = 0；
// 画图
// 大于0就加一个小于0的数，小于0就加一个大于0的数，使整体浮动在x=0附近
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[300005];
int main() {
    //freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, a_max = -1e9-1;
        cin >> n;
        vector<ll> pos; 
        vector<ll> neg;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a_max = max(a_max, a[i]);
        }
        if(a_max == 0) {
            cout << "NO" << endl;
        } 
        else {
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i++) {
                if(a[i] >= 0) pos.push_back(a[i]);
                else neg.push_back(a[i]);
            }
            vector<ll> ans;
            ll pre_sum = 0;
            for(int i = 1; i <= n; i++) {
                if(pre_sum > 0) {
                    ans.push_back(neg.back());
                    neg.pop_back();
                } else {
                    ans.push_back(pos.back());
                    pos.pop_back();
                }
                pre_sum += ans.back();
            }
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        } 
    }
    return 0;
}