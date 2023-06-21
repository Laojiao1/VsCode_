// https://www.luogu.com.cn/problem/P2678
#include <bits/stdc++.h>
using namespace std;
int m, n, L;
int l, r, mid;
long long ans = 0;
const int maxn = 5e5+5;
long long a[maxn];
bool pd(int x) {
    int cnt = 0; // 记录以当前答案实际要挪走的石头数量
    int now = 0; // 记录跳石头的人目前在什么位置
    for(int i = 1; i <= n + 1; i++) {
        if(a[i] - a[now] < x) {
            cnt++;
        } else {
            now = i;
        }
    }
    if(cnt <= m) return true;
    else return false;
}

int main() {
    cin >> L >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = L;
    l = 1, r = L;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(pd(mid)) {
            ans = mid;
            l = mid + 1; // 如果满足条件，就继续向右找看还有没有更大的
        } else { // 反之向左找
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}