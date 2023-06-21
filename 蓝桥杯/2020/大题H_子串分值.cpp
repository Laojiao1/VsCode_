// 寻找每一个字符，前面最后一次出现的位置i和后面第一次出现的位置j, 其贡献度等于i*j
// 求出所有字符的贡献度最后加起来即可
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
string s;
int pre[N], nex[N], a[27]; // a[]记录各个字符的位置
int main() {
    cin >> s;
    s = '0' + s;
    // 找前驱
    for(int i = 1; i <= s.length()-1; i++) {
        int c = s[i] - 'a';
        pre[i] = a[c];
        a[c] = i;
    }
    for(int i = 0; i < 26; i++) {
        a[i] = s.length();
    }
    // 找后继
    for(int i = s.length()-1; i >= 1; i--) {
        int c = s[i] - 'a';
        nex[i] = a[c];
        a[c] = i;
    }
    long long sum = 0;
    for(int i = 1; i <= s.length()-1; i++) {
        sum += (long long)( abs(i - pre[i]) * abs(nex[i] - i) );
    }
    cout << sum << endl;
    return 0;
}