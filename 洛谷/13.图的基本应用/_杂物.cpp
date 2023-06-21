// 方法一：因为任务可以并发，所以一个任务如果有前驱的话，
// 最优方案便是在它的最晚一个前驱结束后就立即开始
// https://www.luogu.com.cn/problem/P1113
// #include <bits/stdc++.h>
// using namespace std;
// int n, num, len, t;
// int ans[10005], maxans;
// int main() {
//     // freopen("in.in", "r", stdin);
//     cin >> n;    
//     for(int i = 1; i <= n; i++) {
//         cin >> num >> len;
//         int temp = 0;
//         while(scanf("%d", &t) && t) {
//             temp = max(ans[t], temp);
//         }
//         ans[num] = temp + len;
//         maxans = max(ans[num], maxans);
//     }
//     cout << maxans << endl;
//     return 0;
// }

// 方法二: 拓扑排序
#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
vector<int> edge[N];
queue<int> q;
int ru[N], ans[N], t[N]; // 入度，答案，时间
int main() {
    //freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num, len, a;
        cin >> num >> len;
        t[num] = len;
        while(scanf("%d", &a) && a) {
            edge[a].push_back(num);
            ru[num]++;
        }
    }
    // 开始拓扑排序
    for(int i = 1; i <= n; i++) {
        if(ru[i] == 0) {
            q.push(i); // 入度为0进队列
            ans[i] = t[i]; // 把答案加到对应结点里
        }
    }
    while(!q.empty()) {
        int head = q.front();
        q.pop();
        for(int i = 0; i < edge[head].size(); i++) {
            // 开始删点
            int u = edge[head][i];
            ru[u]--;
            if(ru[u] == 0) {
                q.push(u);
            }
            ans[u] = max(ans[u], ans[head] + t[u]);
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = max(ret, ans[i]); //  统计答案(找最大的那个就完事了)
    }
    cout << ret << endl;
    return 0;
}