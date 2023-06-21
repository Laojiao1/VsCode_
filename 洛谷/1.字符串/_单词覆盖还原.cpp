//总结：熟练运用或运算
// 1 || 1 -> 1
// 1 || 0 -> 1
// 0 || 1 -> 1
// 0 || 0 -> 0
// 因此可以作为字符串重叠判断
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin , s);
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < s.length()-2; i++) {
        if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') {
            cnt1++;
        }
    }
    for(int i = 0; i < s.length()-3; i++) {
        if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') {
            cnt2++;
        }
    }
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    return 0;
}