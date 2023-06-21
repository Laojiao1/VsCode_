// https://www.luogu.com.cn/problem/P1496
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[20001], b[20001], l = 0;
// a数组存储起点，b数组存储终点，l表示最终长度
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    // 由于起点终点的顺序对答案不产生影响，对a数组和b数组进行排序
    for(int i = 1; i <= n; i++) {
        l += b[i] - a[i];// 加上当前线段长度
        if(i < n)// 如果这条线段不是最后一条线段
            if(b[i] > a[i+1])// 如果这条线段与前一条线段有重复
                l -= b[i] - a[i+1];// 减去重复部分
    }
    cout << l;//输出
    return 0;
}

