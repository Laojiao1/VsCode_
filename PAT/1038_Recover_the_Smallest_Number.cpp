// 贪心，给出一组数字，求他们拼接后最小的数字
#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
bool cmp(string a, string b) {
    return a + b < b + a;
}
int main() {
   // freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    string str[N];
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string res;
    for(int i = 0; i < n; i++) {
        res += str[i];
    }
    while(res.size() > 0 && res[0] == '0') {
        res.erase(res.begin());
    }
    if(res.length() > 0) {
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}