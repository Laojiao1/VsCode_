// 单调队列板子题
// https://www.luogu.com.cn/problem/P2251
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct Node {
    int id;
    int data;
} a[N];
int n, m, ans[N];
deque<Node> q;
void func() {
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && q.back().data >= a[i].data) {
            q.pop_back();
        }
        q.push_back(a[i]);
        while(!q.empty() && q.front().id <= i - m) {
            q.pop_front();
        }
        ans[i] = q.front().data;
    }
    for(int i = m; i <= n; i++) {
        cout << ans[i] << endl;
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].data;
        a[i].id = i;
    }
    func();
    return 0;
}