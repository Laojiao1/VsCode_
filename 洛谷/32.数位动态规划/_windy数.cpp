// 数位DP
// https://www.luogu.com.cn/problem/P2657
// Input: 1 10
// Output: 9

#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int f[N][10]; //f[i][j]表示一共有i位，且最高位数字为j的windy数的个数
int num[N]; //把整数的每一位抠出来存储到数组中

//预处理
void init() {
    for(int i = 0; i <= 9; i++) 
        f[1][i] = 1; //第一位
    for(int i = 2; i < N; i++) { //阶段：枚举位数
        for(int j = 0; j <= 9; j++) { //状态：枚举第i位
            for(int k = 0; k <= 9; k++) { //决策：枚举第i-1位
                if(abs(k-j) >= 2) {
                    f[i][j] += f[i-1][k];
                }
            }
        }
    }
}

int dp(int x) {
    if(!x) return 0;
    int cnt = 0;
    while(x) {
        num[++cnt] = x % 10;
        x /= 10;
    } //把每一位抠出来存到数组中
    int res = 0;
    int last = -2; //last表示上一位数字 设置为-2的原因是保证第一位是1的情况下成立
    for(int i = cnt; i >= 1; i--) { //从高位到低位开始枚举
        int now = num[i]; //把最高位数字提出来
        for(int j = (i == cnt); j < now; j++) { //如果i == cnt的话，则最高位从1开始
            if(abs(j-last) >= 2) res += f[i][j];
        }
        if(abs(now - last) < 2) break; 
        last = now;
        if(i == 1) res++;
    }
    for(int i = 1; i < cnt; i++) {
        for(int j = 1; j <= 9; j++)
            res += f[i][j]; // 累加答案
    }
    return res;
}

int main() {
    init();
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l-1) << endl;
    return 0;
}