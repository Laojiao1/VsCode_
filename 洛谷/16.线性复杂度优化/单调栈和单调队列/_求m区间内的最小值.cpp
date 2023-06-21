// https://www.luogu.com.cn/problem/P1440
// 本题跟扫描差不多,用deque实现单调队列
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
struct Node {
    int data;
    int id;
} a[N];
deque<Node> q;
int n, m;
int arr[N], ans[N];
int main() {
    //freopen("in.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].data);
        a[i].id = i;
    }
    ans[0] = 0;
    for(int i = 1; i < n; i++) {
        while(!q.empty() && q.back().data >= a[i].data)
            q.pop_back(); // 维护单调性，如果队列尾部元素大于当前入队元素，就把尾部元素删掉
        q.push_back(a[i]);
        while(!q.empty() && q.front().id <= i - m) // 维护区间范围
            q.pop_front();
        ans[i] = q.front().data;
    }
    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
// 方法二：
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2000005;
// typedef pair<int, int> a;
// priority_queue<a, vector<a>, greater<a> > q; // 注意优先队列不能放结构体
// priority_queue<a, vector<a>, greater<a> > q2;
// int n, k, arr[N];
// int main() {
//     // freopen("in.in", "r", stdin);
//     scanf("%d %d", &n, &k);
//     for(int i = 1; i <= n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     cout << 0 << endl;
//     for(int i = 1; i < n; i++) {
//         q.push(make_pair(arr[i], i));
//         if(i - k >= 0) { // 当队列中有k个数的时候开始执行出队操作
//             while(q.top().second <= i - k) // 首先剔除队列头部不满足题意的数
//                 q.pop();
//             printf("%d\n", q.top().first);
//         } else {
//             printf("%d\n", q.top().first);
//         }
//     }
//     return 0;
// }
