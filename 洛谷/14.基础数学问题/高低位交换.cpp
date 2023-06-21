// https://www.luogu.com.cn/problem/P1100
#include <bits/stdc++.h>
using namespace std;
unsigned int x; // 注意要开unsigned int是31位，但是存储的是正整数
int main() {
    //freopen("in.in", "r", stdin);
    cin >> x;
    cout << (x << 16 | x >> 16) << endl;
    return 0;
}