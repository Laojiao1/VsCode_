// https://www.luogu.com.cn/problem/P1966
// 揣摩后其实就是求逆序对
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int mod = 1e8-3;
struct Node {
    int id;
    int data;
}a1[N], a2[N];
long long n, b[N];
int f[N];
long long ans;
bool cmp(Node a, Node b) {
    return a.data < b.data;
}
inline void msort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = l;
    msort(l, mid);
    msort(mid + 1, r);
    while(i <= mid && j <= r) {
        if(f[i] <= f[j]) {
            b[k++] = f[i++];
        } else {
            b[k++] = f[j++];
            ans = (ans + mid - i + 1) % mod; // 注意细节
        }
    }
    while(i <= mid) b[k++] = f[i++];
    while(j <= r)  b[k++] = f[j++];
    for(int i = l; i <= r; i++) {
        f[i] = b[i];
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a1[i].data;
        a1[i].id = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a2[i].data;
        a2[i].id = i;
    }
    sort(a1+1, a1+1+n, cmp);
    sort(a2+1, a2+1+n, cmp);
    for(int i = 1; i <= n; i++) {
        f[a1[i].id] = a2[i].id;
    }
    msort(1, n);
    cout << ans << endl;
    return 0;
}