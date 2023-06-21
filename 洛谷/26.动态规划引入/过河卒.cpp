// P1002 https://www.luogu.com.cn/problem/solution/P1002
// DP引入
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// 以马为原点建立坐标轴
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int bx, by, mx, my;
ll f[40][40];
bool s[40][40];

int main() {
    cin >> bx >> by >> mx >> my;
    bx += 2; by += 2; mx += 2; my += 2;//坐标+2以防越界
    f[2][1] = 1;//初始化
    s[mx][my] = 1;// 标记马的位置
    for(int i = 1; i <= 8; i++) {
        s[mx + fx[i]][my + fy[i]] = 1; //把马能走到的位置都标记一下
    }
    // 开始枚举
    for(int i = 2; i <= bx; i++) {
        for(int j = 2; j <= by; j++) {
            if(s[i][j]) continue; //遇到马就跳过
            f[i][j] = f[i-1][j] + f[i][j-1]; // 动态转移方程
        }
    }
    cout << f[bx][by] << endl;
    return 0;
}