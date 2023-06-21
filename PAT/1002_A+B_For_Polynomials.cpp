// 合并同类相
// 数组下标代表指数，数组内的数字代表系数
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
double res[N];
bool flag[N];
int main() {
    int a, b, k;
    double t;
    int cnt = 0;
    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> k >> t; // 输入指数和系数
        res[k] += t;
        if(flag[k] == 0) {
            cnt++;// 记录项数
            flag[k] = 1; // 标记指数已经出现过
        }
    }
    cin >> b;
    for(int i = 0; i < b; i++) {
        cin >> k >> t;
        res[k] += t;
        if(flag[k] == 0) {
            ++cnt;
            flag[k] = 1; // 同上
        }
        if(res[k] == 0) { // 如果系数为0
            cnt--; // 项数减1
        }
    }
    cout << cnt;
    for(int i = N; i >= 0; i--) {
        if(res[i]) {
            printf(" %d %.1f", i, res[i]); // 输出质数和系数
        }
    }
    cout << endl;
    return 0;
}