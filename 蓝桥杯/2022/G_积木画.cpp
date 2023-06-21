#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
const int N = 10000000;
int n, G[N], F[N];
int main() {
    cin >> n;
    F[0] = 1;
    F[1] = 1;
    G[0] = 0;
    G[1] = 1;
    for(int i = 2; i <= n; i++) {
        F[i] = ((F[i-1] + F[i-2]) % Mod + 2 * G[i-2] % Mod) % Mod;
        G[i] = (G[i-1] + F[i-1]) % Mod;
    }
    cout << F[n] % Mod << endl;
    return 0;
}