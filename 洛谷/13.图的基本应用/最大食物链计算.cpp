// https://www.luogu.com.cn/problem/P4017
// 依旧是拓扑排序
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5001;
int ru[maxn], chu[maxn], f[maxn];
int n, m;
queue<int> q;
int ans;
int mp[maxn][maxn];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
        chu[a]++;
        ru[b]++;
    }
    for(int i = 1; i <= n; i++) {
        if(ru[i] == 0) {
            f[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(mp[a][i] == 0) continue;
            ru[i]--;
            f[i] += f[a]; // 继承
            if(ru[i] == 0) {
                if(chu[i] == 0) { // 入度出度都为0，说明已经删除完毕
                    ans += f[i];
                    ans %= 80112002;
                }
                q.push(i); // 入度为0 继续压入队列
            }
        }
    }
    cout << ans << endl;
    return 0;
}