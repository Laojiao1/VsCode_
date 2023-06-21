// 求最近的共同祖先：
// https://www.luogu.com.cn/problem/P3379
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct Node {
    int to;
    int next;
} e[N*2];
int head[N], tot;
int depth[N], f[N][21];
// f[i][j] 表示i结点的2^j级祖先
void add(int x, int y) {
    e[++tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
}
void dfs(int now, int fath) { //now表示当前节点，fath表示它的父亲节点
    f[now][0] = fath; // 从树根节点开始
    depth[now] = depth[fath]+1; // 当前节点的深度 = 父亲节点的深度 + 1
    // 构造ST表
    for(int i = 1; (1<<i) <= depth[now]; i++) { // 倍增算法，通常以2^n为倍率
        f[now][i] = f[f[now][i-1]][i-1];
        //这个转移可以说是算法的核心之一
	    //意思是now的2^i祖先等于now的2^(i-1)祖先的2^(i-1)祖先
        //2^i = 2^(i-1) + 2^(i-1)
    }
    // 对所有边进行维护
    for(int i = head[now]; i != 0; i = e[i].next) {
        if(e[i].to != fath) { 
            dfs(e[i].to, now); // 一直向下dfs，直到所有边
        }
    }
}
int LCA(int a, int b) {
    if(depth[a] > depth[b]) {
        swap(a, b);
    } // 不妨设a的深度大于b的深度，这里的目的是让a处于深度小的，b处于深度大的
    for(int i = 20; i >= 0; i--) {
        if(depth[a] <= depth[b] - (1 << i)) {
            b = f[b][i]; // 一直让b往上跳
        }
    }
    if(a == b) return a; // 跳到了相同结点就返回
    
    // 此循环的目的是为了让a和b跳到距离他们最近祖先的下一个结点
    for(int i = 20; i >= 0; i--) { // 不断向上跳
        if(f[a][i] == f[b][i]) continue; // 如果跳到了同一层就进入下一个循环
        // 注意这里不能为break，因为虽然父节点相等，但是不一定为最近的公共祖先
        else a = f[a][i], b = f[b][i]; // 不相等就让a和b一起向上移
    }
    return f[a][0]; // 返回a的父节点
}
int main() {
    freopen("in.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(s, 0);
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
    return 0;
}

