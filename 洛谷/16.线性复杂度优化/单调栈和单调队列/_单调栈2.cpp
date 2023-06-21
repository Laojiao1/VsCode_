// 寻找数列中第i个元素之后第一个大于ai的元素与ai的距离
// Input:   8
//          73 74 75 71 69 72 76 73
// output : 1 1 4 2 1 1 0 0
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
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = n; i > 0; i--) {
        while(!s.empty() && s.top().data <= a[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? 0 : s.top().id - i;
        Node temp;
        temp.data = a[i];
        temp.id = i;
        s.push(temp);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}