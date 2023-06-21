// 注意运算优先级
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n; // t名同学，n名评委
    double score[101];
    cin >> t >> n;
    double res[101];
    int cnt = 0;
    while(t--) {
        double sum = 0;
        double ans = 0;
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            score[i] = a; 
        }
        sort(score+1, score+1+n);
        for(int i = 2; i <= n-1; i++) {
            sum += score[i];
        }
        ans = sum / (n-2);
        res[++cnt] = ans;
    }
    sort(res+1, res+1+cnt);
    printf("%.2lf", res[cnt]);
    return 0;
}