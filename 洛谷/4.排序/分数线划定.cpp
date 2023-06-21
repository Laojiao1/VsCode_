// 水题
#include <bits/stdc++.h>
using namespace std;
struct Person {
    int k;
    int s;
} p[5005];
int n, m;
int cnt = 0;
bool cmp(Person p1, Person p2) {
    if(p1.s != p2.s) {
        return p1.s > p2.s;
    } else {
        return p1.k < p2.k;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].k >> p[i].s;
    }
    sort(p+1, p+1+n, cmp);
    int num = m * 1.5;
    int sum = p[num].s;
    // cout << sum << endl;
    for(int i = 1; i <= n; i++) {
        if(p[i].s >= sum) {
            cnt++;
        }
    }
    cout << sum << " " << cnt << endl;
    for(int i = 1; i <= cnt; i++) {
        cout << p[i].k << " " << p[i].s << endl;
    }
    return 0;
}