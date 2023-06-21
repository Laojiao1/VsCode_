// // 方法一：dfs + 剪枝回溯 (会超时，只能得一半分)
// #include <bits/stdc++.h>
// using namespace std;
// const int Mod = 1000000007;
// int n, m, flag = 0, k = 2, i = 1, arr[105]; // 0 代表遇到花，1代表遇到店
// // 遇到店一共n次，遇到花一共m次
// void dfs(int x, int y) { // 店和花
//     if(x > n || y > m) return; // 超出遇到店和花的数量了，剪枝
//     if(x < n && y == m) return; // 花遇见完了，但还有店没遇到，剪枝
//     if(x == n && m - y != k) return; // 店遇到完了，但是剩下的酒不够喝或者多了，剪枝
//     if(arr[i-1] = 0 && k == -1) return; // 酒喝完了，但是遇到花了，剪枝
//     if(x == n && y == m && arr[i-1] == 0 && k == 0) {
//         flag = (flag + 1) % Mod;
//         return;
//     }
//     // 遇到花
//     arr[i] = 0;
//     k--;
//     i++;
//     dfs(x, y+1);
//     k++; // 回溯
//     i--;

//     // 遇到店
//     arr[i] = 1;
//     k *= 2;
//     i++;
//     dfs(x+1, y);
//     i--;
//     k /= 2;
// }
// int main() {
//     cin >> n >> m;
//     dfs(0, 0);
//     cout << flag % Mod << endl;
//     return 0;
// }

// 方法二：DP
#include<stdio.h>
#include<string.h>
#define mod 1000000007
#define max 105
int dp[max][max][max];
int main()
{
    int N,M,flag=0,i,j,k;
    scanf("%d%d",&N,&M);
    memset(dp,0,sizeof(dp));
    dp[N][M][2]=1;            //初始化刚开始手里面是有2斗酒
    for(i=N; i>=0; i--)
    {
        for (j = M; j>=0; j--)
        {
            for (k = M; k>=0; k--)
            {
                if(2*k<=M&&i>=1)
                {
                    dp[i-1][j][k<<1]=(dp[i][j][k]+dp[i-1][j][k<<1])%mod;
                }
                if(j>=1&&k>=1)
                {
                    dp[i][j-1][k-1]=(dp[i][j-1][k-1]+dp[i][j][k])%mod; 
                }
            }
        }
    }
    printf("%d",dp[0][1][1]%mod);
    return 0;
}