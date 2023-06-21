// 归并排序模板
#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001];
int n;
void msort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1, k = l;
    msort(l, mid);// 递归左半边
    msort(mid + 1, r); // 递归右半边
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) { // 寻找逆序对
            b[k++] = a[i++]; // 把小的数放入到b[]数组里
        } else {
            b[k++] = a[j++];
        }
    }
    // 如果有剩余，就把余下的放入到b[]里
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    // 最后别忘了拷贝到a[]数组里
    for(int i = l; i <= r; i++) {
        a[i] = b[i];
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    msort(1, n);
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}