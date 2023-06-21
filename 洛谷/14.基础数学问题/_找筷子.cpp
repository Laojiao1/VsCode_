// 位运算，按位
// https://www.luogu.com.cn/problem/P1469
// 异或的两个小小的性质：同为0，异为1
// k个相同的数的异或和，当k为奇数时，结果是这个数本身，否则结果是0 (异或满足交换律和结合律)
// 任何数与0的异或值是它本身。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll n, num, ans;
int main() {
    ios::sync_with_stdio(false);
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        ans ^= num;
    }
    cout << ans << endl;
    return 0;
}