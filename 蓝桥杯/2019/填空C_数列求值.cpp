#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
long long F[20202020];
int main() {
    F[1] = 1;
    F[2] = 1;
    F[3] = 1;
    for(int i = 4; i <= 20190324; i++) {
        F[i] = (F[i-1] + F[i-2] + F[i-3]) % 10000;
    }
    cout << F[20190324] << endl;
    return 0;
}