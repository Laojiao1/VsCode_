// https://www.luogu.com.cn/problem/P1029
// 最大公约数和最小公倍数的乘积就是原两个数的积
// 所以先把两数相乘，再遍历他的因子即可
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x1, x2, ans, flag;
ll gcd(ll x, ll y) { // 辗转相除法求最大公约数
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    cin >> x1 >> x2; // 以x1为最大公约数，x2为最小公倍数
    if(x1 == x2) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i < sqrt(1ll*x1*x2); i++) { // 遍历一半即可
        if((1ll*x1*x2) % i == 0 && gcd(i, (1ll * x1 * x2) / i) == x1) {
            ans++;
            if(1ll*i*i == 1ll*x1*x2) flag = 1; // 不要忘记标记一下完全平方数
        }
    }
    cout << ans*2-flag << endl;
    return 0;   
}