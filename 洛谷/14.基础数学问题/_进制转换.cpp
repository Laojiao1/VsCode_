// https://www.luogu.com.cn/problem/P1143
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
string a;
int c[N], n1, n2, sum, ans, cnt = 0;
int temp;
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n1 >> a >> n2;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < 'A') {
            temp = pow(n1, a.size()-i-1);
            temp *= (a[i] - '0');
            sum += temp;
        } else {
            temp = pow(n1, a.size()-i-1);
            temp *= (a[i] - 'A' + 10); // A:65 a:97
            sum += temp;
        }
    } // 转换为10进制
    while(sum > 0) {
        c[++cnt] = sum % n2;
        sum /= n2;
    }
    for(int i = cnt; i > 0; i--) {
        if(c[i] > 10) printf("%c", c[i] + 'A' - 10);
        else printf("%d", c[i]);
    }
    return 0;
}