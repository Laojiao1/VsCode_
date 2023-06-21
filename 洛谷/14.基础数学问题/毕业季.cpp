// https://www.luogu.com.cn/problem/P1414
// 数论常规题
#include <bits/stdc++.h>
using namespace std;
int n, bus[1000010], maxx = -1;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        maxx = max(maxx, num); // 记录最大能力值
        int m = sqrt(num);
        for(int j = 1; j <= m; j++) { // 求出每个能力值的因数
            if(num % j == 0) {
                bus[j]++; // 记录一个因子
                if(num != j*j) bus[num/j]++; // 记录另一个因子，完全平方数只需要记录一次即可
            }
        }
    }
    int ans = maxx;
    for(int i = 1; i <= n; i++) {
        while(bus[ans] < i) ans--;
        cout << ans << endl;
    }
    return 0;
}