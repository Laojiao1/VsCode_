// P2676
// 排序+贪心
#include <bits/stdc++.h>
using namespace std;
int n;
long long sum, sum2;
int cow[200002];
int cnt = 0;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> n >> sum;
    for(int i = 1; i <= n; i++) {
        cin >> cow[i];
    }
    sort(cow+1, cow+1+n, cmp);
    for(int i = 1; i <= n; i++) {
        sum2 += cow[i];
        cnt++;
        if(sum2 >= sum) {
            cout << cnt << endl;
            break;
        }
    }
    return 0;
}