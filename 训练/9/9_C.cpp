#include <bits/stdc++.h>
using namespace std;
long long maxx = 0, sum = 0;
long long a;
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        maxx = 0, sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            maxx = max(maxx, a); //找到最大值
            sum += a;
        }
        if(maxx*(n-1) > sum) {
            cout << maxx*(n-1) - sum << endl;
        } else {
            if(sum % (n-1) == 0) {
                cout << "0" << endl;
            } else {
                cout << (n-1)-sum%(n-1) << endl;
            }
        }
    }
    return 0;
}

