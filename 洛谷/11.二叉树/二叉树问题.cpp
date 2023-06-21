// 求树的深度，树的宽度，结点间的距离（LCA问题, 求两个结点的最近的共同祖先）
// https://www.luogu.com.cn/problem/P3884
#include <bits/stdc++.h>
using namespace std;
int n;
int fa[101], root[101], son[101];
int depth[101], weith[101];
// 这里是暴力解法
int LCA(int u, int v) {
    if(u == v) return u; // 如果两个根节点都相等的话就返回
    else if(depth[u] == depth[v]) {
        return LCA(fa[u], fa[v]); // 如果深度相等，就往上走
    } else if(depth[u] < depth[v]) {
        return LCA(u, fa[v]); // 如果v深度大，就只让v往上走
    } else {
        return LCA(fa[u], v); // 同理
    }
}
int main() {
    cin >> n;
    depth[1] = 1;
    // 求深度
    for(int i = 1; i <= n-1; i++) {
        cin >> root[i] >> son[i];
        depth[son[i]] = depth[root[i]] + 1; // 递推：子节点的深度等于父节点深度+1
        fa[son[i]] = root[i];
    }
    int x, y;
    cin >> x >> y;
    int max_depth = 1, max_weith = 1;
    for(int i = 1; i <= n; i++) {
        max_depth = max(max_depth, depth[i]); // 求最大深度，即二叉树的深度
        weith[depth[i]]++; // 记录个个深度中有几个结点
    }
    cout << max_depth << endl; // 输出深度
    for(int i = 1; i <= n; i++) {
        max_weith = max(max_weith, weith[i]); // 结点数最多的即为二叉树的宽度
    }
    cout << max_weith << endl; // 输出宽度
    int k = LCA(x, y);
    int dis = (depth[x] - depth[k])*2 + (depth[y] - depth[k]);
    cout << dis << endl; 
    return 0;
}