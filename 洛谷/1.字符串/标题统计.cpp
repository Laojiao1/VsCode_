#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10];
    gets(s); //可以读入空格
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            cnt ++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            cnt++;
        } else if (s[i] >= '0' && s[i] <= '9') {
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}