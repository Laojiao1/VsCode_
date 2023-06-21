// P1067
// 细节贼多的模拟题(做的时候把自己绕晕了orz)
// 考虑各种符号输出的条件即可
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    for(int i = n; i >= 0; i--) {
        cin >> a;
        if(a) {    
            if(i != n && a > 0) cout << "+";// 当不是开头的数并且a>0时输出+
            if(abs(a)>1||i == 0) cout << a;// 当a的绝对值大于1，且最后一项的时候直接输出数字
            if(a == -1 && i) cout << "-"; // 当a等于-1并且i不等于0时输出-
            if(i > 1) cout << "x^" << i;// 当i != 0（i > 1）的时候输出x^
            if(i == 1) cout << "x"; // 当i == 1的时候直接输出一个x
        }
    }
    return 0;
}