// n 个人围成一圈，从第一个人开始报数,
// 数到 m 的人出列，再由下一个人重新从 1 开始报数，
// 数到 m 的人再出圈，依次类推，直到所有的人都出圈，
// 请输出依次出圈人的编号
// 考察队列
#include <bits/stdc++.h>
using namespace std;
int n, m;
queue<int> q;
int main() {
    cin >> n >> m;
    int a = 1;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        // 如果报数报到了m，就出队
        if(a == m) {
            cout << q.front() << " ";
            q.pop();
            a = 1; // 从1开始报数
        } else {
            // 否则把当前队头数放到队尾
            a++;
            q.push(q.front()); // 把队列头放到尾部
            q.pop(); // 出列
        }
    }
    return 0;
}