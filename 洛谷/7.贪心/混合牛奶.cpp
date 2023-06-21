// 水题
#include <bits/stdc++.h>
using namespace std;
struct cow {
    int cost;
    int num;
} c[10001];
int n, m;
long long ans = 0;
bool cmp(cow c1, cow c2) {
    if(c1.cost != c2.cost) {
        return c1.cost < c2.cost;
    } else {
        return c1.num > c2.num;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> c[i].cost >> c[i].num;
    }
    sort(c+1, c+1+m, cmp);
    for(int i = 1; i <= m; i++) {
        if(c[i].num <= n) {
            n -= c[i].num;
            ans += c[i].cost * c[i].num;
        } else {
            ans += c[i].cost * n;
            n = 0;
        }
    }
    cout << ans << endl;
    return 0;
}