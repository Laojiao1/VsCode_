// https://www.luogu.com.cn/problem/P2032
// 单调队列
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef pair<int, int> a;
priority_queue<a, vector<a>, less<a> > q; // 注意优先队列不能放结构体
int n, k, arr[N];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++) {
        q.push(make_pair(arr[i], i));
        if(i - k >= 0) { // 当队列中有k个数的时候开始执行出队操作
            while(q.top().second <= i - k) // 首先剔除队列头部不满足题意的数
                q.pop();
            cout << q.top().first << endl;
        }
    }
    return 0;
}
