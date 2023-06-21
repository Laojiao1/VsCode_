// P1116
// 冒泡排序一共执行的次数
#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
int a[10001];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}