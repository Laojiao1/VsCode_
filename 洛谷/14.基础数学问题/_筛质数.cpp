#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000010;
int vis[N]; // 真为合数
int prime[N];
int cnt;
void Eratosthenes(int n) { // 埃氏筛:从小到大枚举每个数，如果当前数没划掉，必定是质数，记录该质数；枚举当前质数的倍数，必定是合数，划掉合数
    for(ll i = 2; i <= n; i++) {
        if(!vis[i]) {
            prime[++cnt] = i;
            for(ll j = i*i; j <= n; j += i) {
                vis[j] = 1;
            }
        }
    }
}
void get_prime(int n) { // 线性筛法(欧拉筛)
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1; 1ll * i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
} 