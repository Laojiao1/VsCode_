// 方法一：暴力解法，二位前缀和, 80分
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 505;
// int n, m, mp[N][N], f[N][N];
// long long K;
// int main() {
//     //freopen("in.in", "r", stdin);
//     cin >> n >> m >> K;
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             cin >> mp[i][j];
//             f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + mp[i][j]; // 模板
//         }
//     }
//     long long cnt = 0;
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             for(int p = i; p <= n; p++) {
//                 for(int k = j; k <= m; k++) {
//                     if(f[p][k] - f[i-1][k] - f[p][j-1] + f[i-1][j-1] <= K) {
//                         cnt++;
//                     } else {
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }
// 方法二：二位前缀和优化+双指针(满分)
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, mp[N][N], f[N][N];
long long K;
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m >> K;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            mp[i][j] += mp[i-1][j];
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int l = 1, r = 1, sum = 0; r <= m; r++) {
                sum += mp[j][r] - mp[i-1][r];
                while(sum > K) {
                    sum -= mp[j][l] - mp[i-1][l];
                    l++;
                }
                ans += r - l + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}