// 质因子分解
#include <bits/stdc++.h>
using namespace std;
#define N 100001
bool vis[N] = {false};
long prime[N], cnt = 0;
void euler() {
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) {
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt && i * prime[j] <= N; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
bool isprintf = false; // 是否输出符号
void print(long p, long k) {
    if(isprintf) putchar('*');
    if(k > 1) {
        printf("%ld^%ld", p, k);
    } else {
        printf("%ld", p);
    }
    isprintf = true;
}
int main() {
    euler(); // 欧拉筛素数
    long n;
    scanf("%ld", &n);
    printf("%ld=", n);
    bool over = false; // 用作跳出双重循环的标记
    long limit = (long)sqrt(n), i = 0, p = -1, k = 1;
    while(n > 1) {
        while(n % prime[i] != 0) {
            if(prime[i] > limit || ++i == cnt) {
                over = true;
                break;
            }
        }
        if(over) break;
        // 分解质因子
        p = prime[i];
        k = 0;
        do {
            n /= p;
            k++;
        } while(n % p == 0);
        print(p, k);
    }
    // 如果没有质因子，输出其本身
    if(p == -1) {
        printf("%ld", n);
    }
    return 0;
}

