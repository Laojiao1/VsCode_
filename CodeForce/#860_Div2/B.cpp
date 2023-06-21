// 模拟
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    //freopen("in.in", "r", stdin);
    ll t = 0;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> v[n];
        for(ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            for(ll j = 0; j < x; j++) {
                ll y;
                cin >> y;
                v[i].push_back(y);
            }
        }
        bool vis[500005] = {false};
        vector<ll> ans;
        for(ll i = n-1; i >= 0; i--) {
            bool flag = 0;
            for(auto l : v[i]) {
                if(!flag && !vis[l]) {
                    flag = true;
                    ans.push_back(l);
                    vis[l] = true;
                } else {
                    vis[l] = true;
                }
            }
        }
        if(ans.size() == n) {
            reverse(ans.begin(), ans.end());
            for(auto l : ans) cout << l << " ";
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}