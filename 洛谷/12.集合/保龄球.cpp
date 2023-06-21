// 模拟水题
// 注意map容器中find查找的是key值
#include <bits/stdc++.h>
using namespace std;
int n, q;
map<int, int> mp;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        mp[num] = i; 
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int a;
        cin >> a;
        if(mp.find(a) != mp.end()) {
            cout << mp[a] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}