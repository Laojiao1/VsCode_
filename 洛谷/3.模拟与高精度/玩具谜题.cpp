// P1536
#include <bits/stdc++.h>
using namespace std;
pair<int, string> p[100005];
int point = 1;
int n, m;
int a;
void solve1() { // 向左
    cin >> a;
    if(point-a <= 0) {
        point = point-a+n;
    } else {
        point = point-a;
    }
}
void solve2() { //向右
    cin >> a;
    if(point+a > n) {
        point = point + a - n;
    } else {
        point = point + a;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        if(num == 0 && p[point].first == 0) solve1();
        else if(num == 0 && p[point].first == 1) solve2();
        if(num == 1 && p[point].first == 0) solve2();
        else if(num == 1 && p[point].first == 1) solve1();
    }
    cout << p[point].second << endl;
    return 0;
}