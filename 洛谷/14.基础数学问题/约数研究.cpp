// 1-n的因子个数，可以看成共含有2因子的数的个数 + 含有3因子的数的个数…… + 含有n因子的数的个数
// 但在1~n中含有“2”这个因子的数有n/2个，3有n/3个，以此类推，公式就出来了
// https://www.luogu.com.cn/problem/P1403
#include <iostream>
using namespace std;
int n, ans;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        ans += n/i;
    cout << ans;
}