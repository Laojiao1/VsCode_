#include <bits/stdc++.h>
using namespace std;
const int N = 101;
vector<int> children[N], path;
int n, m, target;
int value[N];
bool cmp(int a, int b) {
    return value[a] > value[b];
}
void dfs(int x, int amount) {
    amount += value[x];
    path.push_back(value[x]);
    if(amount > target) {
        path.pop_back();
        return;
    } else if(amount == target && children[x].empty()) {
        for(int i = 0; i < path.size(); i++) {
            if(i > 0) putchar(' ');
            printf("%d", path[i]);
        }
        putchar('\n');
    }
    int l = children[x].size();
    for(int i = 0; i < l; i++) {
        dfs(children[x][i], amount);
    }
    path.pop_back(); // 回溯
}
int main() {
   freopen("in.in", "r", stdin);
    cin >> n >> m >> target;
    for(int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }
    for(int i = 0; i < m; i++) {
        int id, k;
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j++) {
            int t;
            scanf("%d", &t);
            children[id].push_back(t);
        }
        sort(children[id].begin(), children[id].end(), cmp);
    }
    dfs(0, 0);
    return 0;
}