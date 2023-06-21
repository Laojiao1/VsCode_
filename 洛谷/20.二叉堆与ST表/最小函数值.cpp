// https://www.luogu.com.cn/problem/P2085
// 这题不是很难
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q; // 开一个大顶堆
int ans[100001];
int n, m;
int main() { 
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 1; j <= m; j++) {
            int k = a*j*j + b*j + c;
            if(i == 1) q.push(k);
            else {
                if(k < q.top()) {
                    q.pop();
                    q.push(k);
                } else {
                    break; // 如果大于的话直接break，因为按照题意函数的递增的
                }
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        ans[i] = q.top();
        q.pop();
    }
    for(int i = m; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}