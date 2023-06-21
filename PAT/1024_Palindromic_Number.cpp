// 高精度加法
#include <bits/stdc++.h>
using namespace std;
string s, rs;
int cnt_sum;
void add(string &s1, string &s2) { // 高精度加法
    int temp = 0;// 进位
    for(int i = s1.size()-1; i >= 0; i--) {
        int t = (s1[i] - '0') + (s2[i] - '0') + temp;
        s1[i] = t % 10 + '0';
        temp = t / 10;
    }
    if(temp > 0) {
        s1.insert(s1.begin(), temp + '0'); // 在开头插入进制
    }
}
int main() {
    cin >> s >> cnt_sum;
    rs = s;
    reverse(rs.begin(), rs.end());
    int cnt = 0;
    while(cnt < cnt_sum && rs != s) { // 不是回文数字，就一直循环
        add(s, rs);
        rs = s;
        reverse(rs.begin(), rs.end());
        cnt++;
    }
    cout << s << endl;
    cout << cnt << endl;
    return 0;
}