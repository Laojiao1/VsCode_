// 用deque实现单调队列
// 由于是直接比较大小，所以时间和空间不会爆
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
struct Node {
    int data;
    int id;
} a[N];
deque<Node> q;
deque<Node> q2;
int n, m;
int arr[N], ans[N], ans2[N];
void min_Q() {
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && q.back().data >= a[i].data) // 维护单调性
            q.pop_back(); // 如果队尾大，就把队尾元素出队
        q.push_back(a[i]);
        while(!q.empty() && q.front().id <= i - m) // 维护区间大小
            q.pop_front();
        ans[i] = q.front().data;
    }
    for(int i = m; i <= n; i++) {
        printf("%d ", ans[i]);
    }       
}
void max_Q() {
    for(int i = 1; i <= n; i++) {
        while(!q2.empty() && q2.back().data <= a[i].data)
            q2.pop_back();
        q2.push_back(a[i]);
        while(!q2.empty() && q2.front().id <= i - m)
            q2.pop_front();
        ans2[i] = q2.front().data;
    }
    for(int i = m; i <= n; i++) {
        printf("%d ", ans2[i]);
    }
}
int main() {
    freopen("in.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].data);
        a[i].id = i;
    }
    min_Q();
    cout << endl;
    max_Q();
    return 0;
}