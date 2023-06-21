// 二分答案
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
double a[N], b[N]; // a为每秒充电消耗数，b为当前有多少电量
double l, r, mid;
double sum = 0;
double n, p; // 多少个设备、充电宝每秒能充多少电
bool pd(double ans) {
    double q = p * ans; // 充电宝一共能充多少电
    sum = 0; // ans情况下需要多少电
    for(int i = 1; i <= n; i++) {
        if(a[i] * ans <= b[i]) { // 如果总共消耗的电量小于等于其初始电量，忽略该设备
            continue;
        } else {
            sum += (a[i] * ans) - b[i];
        }
    }
    if(sum <= q) return true;
    else return false; 
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    // 特判 充电速度大于全部设备的消耗速度的话就一定能一直用下去
    if(p >= sum) {
        cout << "-1" << endl;
        return 0;
    }
    l = 0, r = 1e10;
    while(r - l > 1e-6) {
        mid = (l + r) / 2;
        if(pd(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}