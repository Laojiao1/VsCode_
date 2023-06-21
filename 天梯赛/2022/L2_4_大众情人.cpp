#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
struct Node {
    char sex;
    int idx;
    int num; // num记录最大距离
} a[N], b[N], c[N];
int e[N][N], cnt1, cnt2;
bool cmp(Node x, Node y) {
    if(x.num == y.num) {
        return x.idx < y.idx;
    }
    return x.num < y.num;
}
int main() {
    //freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) e[i][j] = 1e9;
            else e[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        getchar();
        int m;
        scanf("%c%d", &a[i].sex, &m);
        a[i].idx = i;
        for(int j = 1; j <= m; j++) {
            int x, y;
            scanf("%d:%d", &x, &y);
            e[i][x] = y;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    // 对每个人求异性缘
    for(int i = 1; i <= n; i++) {
        int res = 0;
        int j;
        for(j = 1; j <= n; j++) {
            if(a[i].sex != a[j].sex) {
                res = max(res, e[j][i]); // 注意是异性对自己的距离，所以是j->i
            }
        }
        if(a[i].sex == 'F') {
            b[++cnt1].num = res;
            b[cnt1].idx = a[i].idx;
        } else {
            c[++cnt2].num = res;
            c[cnt2].idx = a[i].idx;
        }
    }
    // 排序找到异性距离最大中最小的
    sort(b+1, b+1+cnt1, cmp);
    sort(c+1, c+1+cnt2, cmp);
    int i = 1, ok = 0;
    while(b[i].num == b[1].num && i <= cnt1) {
        if(ok) cout << " ";
        cout << b[i].idx;
        i++;
        ok = 1;
    }
    i = 1;
    ok = 0;
    cout << endl;
    while(c[i].num == c[1].num && i <= cnt2) {
        if(ok) cout << " ";
        cout << c[i].idx;
        i++;
        ok = 1;
    }
    return 0;
}
