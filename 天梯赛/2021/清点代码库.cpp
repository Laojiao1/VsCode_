#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
#define ll long long
map<vector<int>, int> mp;
int main() {
    freopen("in.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        vector<int> v;
        v.clear();
        for(int j = 1; j <= m; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        if(!mp[v]) {
            mp[v] = 1;
        } else {
            mp[v]++;
        }
    }
    vector< pair<int, vector<int>> > ans;
    for(auto it : mp) {
        ans.push_back({-it.second, it.first});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << -it.first << " ";
        for(auto l : it.second) {
            cout << l << " ";
        }
        cout << endl;
    }
    return 0; 
}