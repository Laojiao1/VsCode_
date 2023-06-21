#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10005;
vector<int> a[N];
vector<int> ans;
bool vis[N] = {false};
void dfs(int u, vector<int>& p) { // u:当前遍历到的结点，p为序列数组
    if(p.size() > ans.size()) {
        ans.clear();
        ans = p;
    }
    for(int i = 0; i < a[u].size(); i++) {
        p.push_back(a[u][i]);
        dfs(a[u][i], p);
        p.pop_back(); // 回溯
    }
}
int main() {
    freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) {
            int id;
            cin >> id;
            a[i].push_back(id);
            vis[id] = 1;
        }
        if(a[i].size() != 0) {
            sort(a[i].begin(), a[i].end());
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) { // 从根节点开始搜
            vector<int> p;
            p.push_back(i);
            dfs(i, p);
            break;
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}