#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 210;
int color[N], n, m;
int dp[N];
int main() {
   // freopen("in.in", "r", stdin);
    cin >> n >> m;
    fill(color, color + M, -1);
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        color[num] = i;
    }
    int len = 0, a[N], L, res = -1;
    cin >> L;
    for(int i = 0; i < L; i++) {
        int num;
        cin >> num;
        if(color[num] >= 0) {
            a[len++] = color[num];
        }
    }
    for(int i = 0; i < len; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j]) {
                dp[i] = dp[j] + 1;
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}