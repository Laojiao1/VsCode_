// 打表求子串即可
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        string ans = "FBFFBFFBFBFFBFFBFBFFBFFB";
        if(ans.find(s) != string::npos){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}