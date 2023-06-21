// https://www.luogu.com.cn/problem/P4715
#include <bits/stdc++.h>
using namespace std;
int n;
queue<pair<int, int> > q; // first-国家，second-实力
int main() {
    cin >> n;
    n = 1 << n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        q.push(make_pair(i, num)); // 把国家编号和实力入队
    }
    while(q.size() > 2) {
        pair<int, int> x, y; 
        // 访问头两个元素进行比较
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        if(x.second > y.second) { // 比较出较大的放入队列尾部
            q.push(x);
        } else {
            q.push(y);
        }
    }
    pair<int, int> a, b;
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    if(a.second > b.second) {
        cout << b.first << endl;
    } else {
        cout << a.first << endl;
    }
    return 0;
}