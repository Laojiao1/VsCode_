// 二分
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int sum[N], total, m;
int lower(int l, int r, int x) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if(sum[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
int main() {
    freopen("in.in", "r", stdin);
    int nears = INT_MAX;
    cin >> total >> m;
    for(int i = 1; i <= total; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    for(int i = 1; i <= total; i++) {
        int j = lower(i, total, sum[i-1] + m);
        if(sum[j-1] - sum[i-1] == m) { 
            nears = m;
            break;
        } else if(j <= total && sum[j-1] - sum[i-1] < m) {
            nears = min(nears, sum[j] - sum[i-1]);
        }
    }
    for(int i = 1; i <= total; i++) {
        int j = lower(i, total, sum[i-1] + nears);
        if(sum[j] - sum[i-1] == nears) {
            cout << i << "-" << j << endl;
        }
    }
    return 0;
}