#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    string ans = "";
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < a.length() - 1;i ++) {
        for (int j = 0; j < b.length() - 1; j++) {
            if (a[i] == b[j] and a[i + 1] == b[j + 1]) {
                ans.push_back(a[i]);
                ans.push_back(a[i + 1]);
                break;
            }
        }
        if (ans.size() != 0)
            break;
    }
    if(a[0]==b[0])
        cout<<"YES"<<endl<<a[0]<<"*"<<endl;
    else if(a[a.size()-1]==b[b.size()-1])
        cout<<"YES"<<endl<<"*"<<a[a.size()-1]<<endl;
    else if(ans.size() != 0)
        cout<<"YES"<<endl<<"*"<<ans<<"*"<<endl;
    else
        cout<<"NO"<<endl;
    return;
}
int main() {
    freopen("in.in", "r", stdin);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k; cin >> k;
    while (k --)
        solve();

}