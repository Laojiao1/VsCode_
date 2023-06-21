#include <bits/stdc++.h>
using namespace std;
char num[10];
int main() {
    int a, b, cnt = 0, len = 0;
    bool flag;
    cin >> a >> b;
    int ans = a + b;
    stack<int> s;
    if(ans < 0) {
        flag = 0;
    } else if(ans > 0) {
        flag = 1;
    } else {
        cout << '0' << endl;
        return 0;
    }
    ans = abs(ans);
    if(flag == 0) {
        cout << '-';
    }
    while(ans) {
        if(cnt != 0 && cnt % 3 == 0) {
            num[len++] = ',';
        }
        num[len++] = ans % 10 + '0';
        ans /= 10;
        ++cnt;
    }
    for(int i = len-1; i>= 0; i--) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}