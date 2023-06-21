// https://www.luogu.com.cn/problem/P1259
// 厚颜无耻的打表
#include <bits/stdc++.h>
using namespace std;
int n;
char ch[205];
string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
void print() {
    for(int i = 1; i <= 2*n + 2; i++) {
        putchar(ch[i]);
    }
    cout << endl;
}
void swapp(char &a, char &b) {
    char t = a;
    a = b;
    b = t;
}
void movechess(int start, int end) {
    swapp(ch[start], ch[end]);
    swapp(ch[start + 1], ch[end + 1]);
    print();
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ch[i] = 'o';
    }
    for(int i = n+1; i <= 2*n; i++) {
        ch[i] = '*';
    }
    ch[2*n+1] = '-', ch[2*n+2] = '-';
    print();
    int len = n;
    while(1) {
        movechess(len, 2*len+1);
        len--;
        if(len == 3) {
            break;
        }
        movechess(len+1, 2*len+1);
    }
    string s = "";
    for(int i = 1; i <= n-4; i++) {
        s += "o*";
    }
    for(int i = 0; i < 4; i++) {
        cout << out[i] << s << endl;
    }
    return 0;
}