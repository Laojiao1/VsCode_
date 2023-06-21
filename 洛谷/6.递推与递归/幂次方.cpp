// 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//递归递归 https://www.luogu.com.cn/problem/P1010
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void solve(int x) {
    cout << "2";
    int a = 1, cnt = 0;
    while(x >= a) {
        cnt++;
        a *= 2;
    } // 找到离x最近的2的n次幂
    // cout << cnt << endl; 
    cnt--; //这里会多计算一次，所以要减去
    if(cnt == 0 || cnt == 2) printf("(%d)", cnt);// 0 和 2需要输出
    if(cnt >= 3) { // 括号的判断
        cout << "(";
        solve(cnt); // 递归
        cout << ")";
    }
    x = x - pow(2, cnt);
    if(x) {
        cout << "+";
        solve(x);
    }
}
int main() {
    cin >> n;
    solve(n);
    return 0;
}