// 水题
#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100001];
int n, a;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}
int cnt = 1;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p+1, p+1+n, cmp);
    a = p[1].second;
    for(int i = 2; i <= n; i++) {
        if(p[i].first >= a) { // 记录上次的时间结束点
            cnt++;
            a = p[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}
