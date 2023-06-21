// https://www.luogu.com.cn/problem/P1241
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
string s;
int pos[N];
int main() {
    cin >> s;
    int i, j;
    for(i = 0; i < s.length(); i++) {
        if(s[i] == ')') {
            for(j = i-1; j >= 0; j--) {
                if(s[j] == '(' && !pos[j]) { // 找到"("并且没被匹配过
                    pos[i] = 1;
                    pos[j] = 1; // 标记位置
                    break;
                } else if (s[j] == '[' && !pos[j]) { 
                    // 如果往前找找到了落单的'[', 就停止寻找
                    break;
                }
            }
        } else if (s[i] == ']') {
            for(j = i-1; j >= 0; j--) {
                if(s[j] == '[' && !pos[j]) {
                    pos[i] = 1;
                    pos[j] = 1; // 标记位置
                    break;
                } else if (s[j] == '(' && !pos[j]) {
                    break;
                }
            }
        }
    }
    for(int i = 0; i < s.length(); i++) {
        if(!pos[i]) {
            if(s[i] == '(' || s[i] == ')') {
                cout << "()";
            } else if(s[i] == '[' || s[i] == ']') {
                cout << "[]";
            }
        } else {
            cout << s[i];
        }
    }
    return 0;
}
