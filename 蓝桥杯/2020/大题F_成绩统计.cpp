#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(num >= 60) {
            cnt1++;
        }
        if(num >= 85){
            cnt2++;
        }
    }
    double ans1 = 1.0*cnt1 / n * 100;
    double ans2 = 1.0*cnt2 / n * 100;
    printf("%.0lf%%\n", ans1);
    printf("%.0lf%%\n", ans2);
    return 0;

}