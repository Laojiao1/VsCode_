// 只要没越界就继续向上下搜，全部搜完得到答案
// 直接搜，剪枝都不用
// https://www.luogu.com.cn/problem/P1135
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int ans = 1 << 30;
int to[205];
bool vis[205];
void dfs(int now, int sum) { // now表示当前搜到的楼层, sum表示按钮次数
    if(now == b) {
        ans = min(ans, sum);
    }
    if(sum > ans) {
        return;
    }
    vis[now] = 1; // 标记该楼层已访问
    if(now + to[now] <= n && !vis[now + to[now]]) {
        dfs(now + to[now], sum + 1); // 向上搜
    }
    if(now - to[now] >= 1 && !vis[now - to[now]]) {
        dfs(now - to[now], sum + 1); // 向下搜
    }
    vis[now] = 0; // 回溯
}
int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> to[i];
    }
    vis[a] = 1;
    dfs(a, 0);
    if(ans != 1 << 30) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}