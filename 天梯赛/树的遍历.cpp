#include <bits/stdc++.h>
using namespace std;
const int N = 35;
#define x first
#define y second
pair<int, int> tree[N];
int post[N], in[N];
int n;
int build(int la, int lb, int ra, int rb) {
    if(la > lb || ra > rb) return 0;
    int root = post[rb];
    int p = la;
    while(in[p] != root) p++;
    int cnt = p - la;

    tree[root].x = build(la, p-1, ra, ra + cnt - 1);
    tree[root].y = build(p + 1, lb, ra + cnt, rb - 1);
    return root;
}
void dfs(int root) {
    queue<int> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        if(tree[t].x) q.push(tree[t].x);
        if(tree[t].y) q.push(tree[t].y);
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> post[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> in[i];
    }
    int root = build(1, n, 1, n);
    dfs(root);
    return 0;
}