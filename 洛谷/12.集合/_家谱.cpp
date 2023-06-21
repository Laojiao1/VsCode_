// 字符串并查集
// https://www.luogu.com.cn/problem/P2814
#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
string s, father;
string find_(string s) {
    if(mp[s] == s) return s;
    else return mp[s] = find_(mp[s]);
}
int main() {
    char ch;
    cin >> ch;
    while(ch != '$') {
        cin >> s;
        if(ch == '#') {
            father = s; // 记录一下父亲结点
            if(mp[s] == "") { // 注意这里当mp[s]为空的时候才进行赋值
                mp[s] = s;
            }
        } else if(ch == '+') {
            mp[s] = father; // 合并
        } else {
            cout << s << " " << find_(s) << endl;
        }
        cin >> ch;
    }
    return 0;
}