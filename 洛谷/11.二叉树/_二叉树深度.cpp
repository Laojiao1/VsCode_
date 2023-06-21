// https://www.luogu.com.cn/problem/P4913
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct BinNode {
    int left;
    int right;
}Tree[maxn];
int n, ans = -1;
void dfs(int root, int step) {
    if(root == 0) return; // 递归出口
    ans = max(ans, step);
    dfs(Tree[root].left, step+1);
    dfs(Tree[root].right, step+1);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> Tree[i].left >> Tree[i].right;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}