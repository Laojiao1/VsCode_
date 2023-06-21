// 直接搜索即可
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int team[N][6];
int vis[N];
int max_sum = 0;
void dfs(int index, int sum) {
    if(index == 6) {
        max_sum = max(sum, max_sum);
        return;
    }
    for(int i = 0; i < 20; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(index+1, sum + team[i][index]);
            vis[i] = 0;
        }
    }
}
int main() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> team[i][j];
        }
    }
    dfs(1, 0);
    cout << max_sum << endl;
    return 0;
}
