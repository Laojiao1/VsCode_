// 状压DP
// 洛谷 P1896
// 在N×N的棋盘里面放K个国王，使他们互不攻击，共有多少种摆放方案。
// 国王能攻击到它上下左右，以及左上左下右上右下八个方向上附近的各一个格子，
// 共8个格子。

// 状态方程 f[i][st][j] 代表第0~i行总共放了j个国王，并且第i行状态为st的方案数
// ans = sum(f[i-1][st2][j-c(st)]);
// c(st) 表示在st二进制状态下，有多少个1（1代表国王）

// 样例：
// 3 2
// 输出：
// 16

#include <bits/stdc++.h>
using namespace std;
int n, k;
long long f[9][1<<9][82]; // 1 << 9 = 2^9-1;
long long ans = 0;

int c(int st) { // 返回st二进制状态下存在多少个1
    int cnt = 0;
    while(st) {
        if(st % 2) cnt ++;
        st /= 2;
    }
    return cnt;
    // return __builtin_popcount(st); // 直接返回一个数的二进制中有多少1
}

bool check1(int st) { // 判断单行状态下的st是否满足题意（合法）
    for(int i = 0; i < n; i++) {
        if( (st & (1<<i)) && (st & (1<<(i+1))) ) { // &运算，两个都为1结果才为1
            return false;
        }
    }
    return true;
}

bool check2(int st, int st2) { //判断当前行状态st和它的上一行状态st2之间的关系是否满足题意
    for(int i = 0; i < n; i++) {
        if(st & (1<<i)) {
            if(st2 & (1<<i)) return false;
            else if(i+1 < n && (st2 & (1<<(i+1)))) return false;
            else if(i-1 >= 0 && (st2 & (1<<(i-1)))) return false;
        }
    }
    return true;
}
    
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) { // 遍历每一行
        for(int st = 0; st < (1<<n); st++) { // 遍历每一种状态
            if(!check1(st)) continue; // 如果不满足题意，跳过
            if(i == 0) f[i][st][c(st)] = 1; // 如果是第一行，则只有一种方法
            else {
                for(int j = c(st); j <= k; j++) { // 遍历其余行
                    for(int st2 = 0; st2 < (1<<n); st2++) { // 遍历上一行的状态
                        if(!check1(st2) || !check2(st, st2)) continue; // 不满足题意直接跳过
                        f[i][st][j] += f[i-1][st2][j-c(st)]; // 状态转移方程
                    }
                }
            }
        }
    }
    for(int st = 0; st < (1<<n); st++) {
        ans += f[n-1][st][k]; // 累加出答案
    }
    printf("%lld\n", ans);
    return 0;
}