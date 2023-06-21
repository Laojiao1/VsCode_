// 知识点:公共质因数求法, 并查集
// https://www.luogu.com.cn/problem/P1621
#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int ans = 0;
int f[100005];
int vis[100005];
int find(int x) {
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int main() {
    cin >> n >> m >> p;
    ans = m - n + 1; // 每次合并减去1即可
    for(int i = n; i <= m; i++) {
        f[i] = i;
    }
    for(int i = 2; i <= m; i++) {
        if(!vis[i]) {
            if(i >= p) { // 当前数大于p才能进行合并操作
                for(int j = i*2; j <= m; j += i) {
                    vis[j] = 1;
                    if(j - i >= n && find(j) != find(j - i)) {
                        // 将当前被筛的数与上一个被筛的数合并
                        // 注意当前数要在n~m之间
                        f[find(j)] = find(j-i);
                        ans--;
                    }
                }
            } else {
                for(int j = i*i; j <= m; j += i) {
                    vis[j] = 1; // 埃氏筛
                }
            }
        }
    }  
    cout << ans << endl;
    return 0;
}