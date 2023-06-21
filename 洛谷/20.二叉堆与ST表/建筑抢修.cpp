// https://www.luogu.com.cn/problem/P4053
// 贪心 + 优先队列
// 不怎么难(竟然还是蓝题)
#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int n, ans = 0;
int t1 = 0; // 已经经历过的时间
struct Node {
    int w;
    int t;
} a[N];
priority_queue<int> q;
bool cmp(Node a1, Node a2) {
    return a1.t < a2.t;
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].t;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++) {
        if(t1 + a[i].w <= a[i].t) {
            q.push(a[i].w); // 如果能修，就把w入队
            ans++;
            t1 += a[i].w;
        } else { 
            if(a[i].w < q.top()) { // 如果当前所需时间比队列头所需时间小的话
                t1 -= q.top(); // 改修此楼
                q.pop();
                q.push(a[i].w);
                t1 += a[i].w;
            }
        }
    }
    cout << ans << endl;
    return 0;
}