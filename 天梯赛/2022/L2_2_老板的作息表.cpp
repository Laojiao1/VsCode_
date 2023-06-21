#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
map<string, int> vis;
set<string> st;
void func(string s) {
    if(vis[s] == 2 || s == "00:00:00" || s == "23:59:59") {
        st.erase(s); // 重复删除
    } else {
        st.insert(s); // 否则记录
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    int n; cin >> n;
    int j = 0;
    while(n--) {
        string s1, s2;
        char ch;
        cin >> s1 >> ch >> s2;
        vis[s1]++, vis[s2]++;
        func(s1), func(s2);
    }
    if(!vis["00:00:00"]) st.insert("00:00:00");
    if(!vis["23:59:59"]) st.insert("23:59:59");
    for(auto i: st) {
        ++j;
        cout << i;
        j & 1 ? cout << " - " : cout << endl;
    }
}