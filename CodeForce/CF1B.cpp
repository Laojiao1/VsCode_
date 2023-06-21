#include <bits/stdc++.h>
using namespace std;
char apt[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, len;
string str;
void solve(bool mode) {
    int col = 0, row = 0; // col列号，row行号
    if(mode == 1) {
        int R = str.find("R"), C = str.find("C");
        for(int i = R + 1; i < C; i++) {
            row = row * 10 + str[i] - '0';
        }
        for(int i = C + 1; i < len; i++) {
            col = col * 10 + str[i] - '0';
        }
        string ans;
        while(col > 0) {
            int temp = col % 26;
            if(temp == 0) temp = 26, col -= 26; // 特判
            ans += apt[temp];
            col /= 26;
        }
        reverse(ans.begin(), ans.end()); // 记得反转
        cout << ans << row << endl;
    } else {
        for(int i = 0; i < len; i++) {
            if(!isdigit(str[i])) {
                col = col * 26 + str[i] - 'A' + 1;
            } else {
                row = row * 10 + str[i] - '0';
            }
        }
        cout << "R" << row << "C" << col << endl;
    }  
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    while(n--) {
        cin >> str;
        bool flag = 0, mode = 0;
        len = str.length();
        for(int j = 0; j < len; j++) {
            if(isdigit(str[j])) flag = 1;
            if(flag && str[j] == 'C') {
                mode = 1;
                break;
            }
        }
        solve(mode);
    }
    return 0;
}