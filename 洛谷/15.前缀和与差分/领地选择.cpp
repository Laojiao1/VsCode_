// https://www.luogu.com.cn/problem/P2004
// 二维前缀和
#include <bits/stdc++.h>
using namespace std;
int mp[1001][1001], sum[1001][1001];
int N, M, C;
int xx, yy;
int ans = -999999999;
int main() {
    //freopen("in.in", "r", stdin);
    cin >> N >> M >> C;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> mp[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mp[i][j];
        }
    }
    for(int i = C; i <= N; i++) {
        for(int j = C; j <= M; j++) {
            if(sum[i][j] - sum[i-C][j] - sum[i][j-C] + sum[i-C][j-C] > ans) {
                ans = sum[i][j] - sum[i-C][j] - sum[i][j-C] + sum[i-C][j-C];
                xx = i-C+1;
                yy = j-C+1;
            }
        }
    }
    cout << xx << " " << yy << endl;
    return 0;
}