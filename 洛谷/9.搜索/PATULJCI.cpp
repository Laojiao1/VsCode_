// https://www.luogu.com.cn/problem/P6314#submit
// dfs
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N], ans[N];
bool dfs(int i, int cnt, int cur){
    if (cur == 100 && cnt == 7){
        return true;
    }
    if (cur > 100){
        return false;
    }
    for (int j = i + 1; j <= 9; j++){
        if (dfs(j, cnt + 1, cur + a[j])){
            ans[cnt + 1] = a[j];
            return true;
        }
    }
    return false;
}
int main() {
   freopen("in.in", "r", stdin);
    for(int i = 1; i <= 9; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    for(int i = 1; i <= 7; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}