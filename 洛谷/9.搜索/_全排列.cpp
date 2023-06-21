// 经典例题
// 输入一个整数 n
// 求出其1 - n的全排列
// 回溯与搜索的模板
// void dfs(int x) {
//     if(到目的地) {
//         输出解
//         return;
//     } else {
//         for(int i = 1; i <= n; i++) { // n代表有多少方案
//             if(方案可行) {
//                 保存路径
//                 dfs(x+1);
//                 恢复保存状态;
//             }
//         }
//     }
// }
#include <bits/stdc++.h>
using namespace std;
int n;
int vis[101], ans[101];
void dfs(int k) {
    if(k > n) {
        for(int i = 1; i < k; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    } else {
        for(int i = 1; i <= n; i++) { 
            if(!vis[i]) {
                vis[i] = 1;
                ans[k] = i;
                dfs(k + 1);
                vis[i] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}