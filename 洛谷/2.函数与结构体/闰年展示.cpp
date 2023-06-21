#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    int rn[2000];
    int cnt = 0;
    cin >> x >> y;
    for(int i = x; i <= y; i++) {
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            rn[++cnt] = i;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i++) {
        cout << rn[i] << " ";
    }
    cout << endl;
    return 0;
}