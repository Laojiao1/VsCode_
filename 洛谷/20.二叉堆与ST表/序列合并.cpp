// 跟求最小函数值思路一样
// https://www.luogu.com.cn/problem/P1631
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n, ans[100001];
int A[100001], B[100001];
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    sort(B+1, B+1+n); // 排个序优化一下
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int k = A[i] + B[j];
            if(i == 1) q.push(k);
            else {
                if(k < q.top()) {
                    q.pop();
                    q.push(k);
                } else {
                    break; 
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = q.top();
        q.pop();
    }
    for(int i = n; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}