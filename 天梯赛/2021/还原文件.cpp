#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<int> v[N], ans;
int a[N];
int n, m;
bool vis[N]; // 记录当前纸条是否被使用过
void dfs(int x) {
    if(x == n-1) {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= m; i++) {
        if(!vis[i]) {
            int flag = 1;   
            for(int j = 0; j < v[i].size(); j++) {
                if(v[i][j] != a[x+j]) {
                    flag = 0;
                }
            }
            if(flag) {
                ans.push_back(i);
                vis[i] = 1;
                dfs(x + v[i].size()-1);
                vis[i] = 0;
                ans.pop_back();
            }
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        while(k--) {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }
    dfs(0);
    return 0;
}

