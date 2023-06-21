// https://www.luogu.com.cn/problem/P1241
#include <bits/stdc++.h>
using namespace std;
string s;
int pos[105];
int main() {
    cin >> s;
    int i, j;
    for(i = 0; i < s.length(); i++) {
        if(s[i] == ')') {
            for(j = i-1; j >= 0; j--) {
                if(s[j] == '(' && !pos[j]) { // 找到"("并且没被匹配过
                    pos[i] = 1;
                    pos[j] = 1; // 标记位置
                    break; // 不需要再找了直接退出循环
                } else if (s[j] == '[' && !pos[j]) { 
                    // 如果往前找找到了落单的'[', 就停止寻找
                    break;
                }
            }
            // 同理
        } else if (s[i] == ']') {
            for(j = i-1; j >= 0; j--) {
                if(s[j] == '[' && !pos[j]) {
                    pos[i] = 1;
                    pos[j] = 1; 
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
            } else {
                cout << "[]";
            }
        } else {
            cout << s[i];
        }
    }
    return 0;
}