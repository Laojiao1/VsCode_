// https://www.luogu.com.cn/problem/P1908
// 归并排序做法（还可以用树状数组）：
// 如果我们想要将一个序列排成从小到大有序的，
// 那么每次划分后合并时左右子区间都是从小到大排好序的，
// 我们只需要统计右边区间每一个数分别会与左边区间产生多少逆序对即可。
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, a[N], b[N];
long long ans;
void solve(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = l;
    solve(l, mid);
    solve(mid + 1, r);
    // 默认左边小右边大了
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) { // 合并
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    // 跳出来的条件有可能只是while条件其中一项没有满足
    // 因此要处理区间剩余的数
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = l; i <= r; i++) { // 再把排好序的数放到a数组里
        a[i] = b[i];
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    solve(1, n);
    cout << ans << endl;
    return 0;
}