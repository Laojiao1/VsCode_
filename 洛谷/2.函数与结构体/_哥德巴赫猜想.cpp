#include <bits/stdc++.h>
using namespace std;
bool solve(int x) {
    if(x == 1) {
        return false;
    }
    if(x == 2) {
        return true;
    }
    for(int i = 2; i < x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        if(i % 2 == 0) {
            for(int j = 2; j <= i/2; j++) {
                if(solve(j) && solve(i-j)) {
                    printf("%d=%d+%d\n", i, j, i-j);
                    break;
                }
            }
        }
    }
    return 0;
}