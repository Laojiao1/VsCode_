// https://www.luogu.com.cn/problem/P1449
// 考察栈，经典题
#include <bits/stdc++.h>
using namespace std;
char ch;
stack<int> n;
int x, y, z;
int main() {
    while(ch != '@') {
        ch = getchar();
        switch(ch) {
            case '+':
            {
                x = n.top(); n.pop(); 
                y = n.top(); n.pop();
                n.push(x + y);
                break;
            }
            case '-':
            {
                x = n.top(); n.pop(); 
                y = n.top(); n.pop();
                n.push(y - x);
                break;
            }
            case '*':
            {
                x = n.top(); n.pop(); 
                y = n.top(); n.pop();
                n.push(x * y);
                break;
            }
            case '/':
            {
                x = n.top(); n.pop(); 
                y = n.top(); n.pop();
                n.push(y / x);
                break;
            }
            case '.':
            {
                n.push(z);
                z = 0;
                break;
            }
            default:
            {
                z = z * 10 + ch - '0';
                break;
            }

        }
    }
    cout << n.top() << endl;
    return 0;
}