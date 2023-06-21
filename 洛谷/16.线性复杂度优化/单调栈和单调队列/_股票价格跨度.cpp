// https://leetcode.cn/problems/online-stock-span/
// 单调递减栈
// 例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]
// 那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+6;
int ans[N], n, a[N];
struct Node {
    int id;
    int data;
};
stack<Node> s;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.top().data <= a[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? 1 : i - s.top().id;
        Node temp;
        temp.data = a[i];
        temp.id = i;
        s.push(temp);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}