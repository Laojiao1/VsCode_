// 快排模板
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int n, a[maxn];
void mysort(int l, int r) { // 利用二分思想
    int mid = a[(l+r)/2]; // 取中间数
    int i = l, j = r;
    do {
        while(a[i] < mid) i++; // 查找左半部分比中间数大的数
        while(a[j] > mid) j--; // 查找右半部分比中间数小的数
        if(i <= j) { // 如果满足排序条件（左小右大）的数
            swap(a[i], a[j]); // 交换
            i++;
            j--;
        }
    } while(i <= j); // 注意要有 “=” 号
    if(l < j) mysort(l, j); // 递归搜索左半部分
    if(i < r) mysort(i, r); // 递归搜索右半部分
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    mysort(1, n);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}