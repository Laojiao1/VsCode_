// https://www.luogu.com.cn/problem/P1168
// 利用大根堆和小根堆
// 让大根堆维护小数据，小根堆维护大数据
// 当两个堆中元素个数差值为1时，中位数为其中元素个数多的堆的堆顶的值
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q2; // 小根堆
priority_queue<int, vector<int>, less<int> > q1; // 大根堆
int n, num;
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> num;
    q1.push(num);
    cout << q1.top() << endl;
    for(int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        if(a > q1.top()) q2.push(a);
        else q1.push(a);
        while(fabs(q1.size() - q2.size()) > 1) {
            if(q1.size() > q2.size()) q2.push(q1.top()), q1.pop();
            else q1.push(q2.top()), q2.pop();
        }
        if(i % 2 == 1) {
            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
        }
    }
    return 0;
}
