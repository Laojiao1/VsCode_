// https://www.luogu.com.cn/problem/P1045
// 快速幂 + 高精度
// 求2^p-1的后500位数，即2^p-1的位数
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int p, base[1100], power[1100], save[1100];
// base[]存储底数, power[]存储指数, save[]临时数组
void func1() { // base = base * power
    memset(save, 0, sizeof(save));
    for(int i = 1; i <= 500; i++) {
        for(int j = 1; j <= 500; j++) {
            save[i+j-1] += base[i] * power[j];
            save[i+j] += save[i+j-1] / 10;
            save[i+j-1] %= 10;
        }
    }
    memcpy(base, save, sizeof(base)); // 记得最后拷贝在base里
}
void func2() { // power = power * power
    memset(save, 0, sizeof(save));
    for(int i = 1; i <= 500; i++) {
        for(int j = 1; j <= 500; j++) {
            save[i+j-1] += power[i] * power[j];
            save[i+j] += save[i+j-1] / 10;
            save[i+j-1] %= 10;
        }
    }
    memcpy(power, save, sizeof(power));
}
int main() {
    cin >> p;
    cout << (int)(p * log10(2)) + 1;
    // 2^p-1的位数与2^p位数一样，因此只需要求2^p的位数就行
    // 因为10^n位数等于n+1, 因此想到把2^n化为10^n
    // 因为10^log10(2) = 2, 不妨设k = 2^p
    // 因此有 k = (10^log10(2))^p
    // 根据乘方原理得：k = 10^log10(2)*p
    // 因此2^p位数 = log10(2)*p + 1 (记得转化为int)
    base[1] = 1; // 保存初始指数
    power[1] = 2; // 保存初始底数
    while(p > 0) {
        if(p & 1) {
            func1();
        }
        p >>= 1;
        func2();
    }
    base[1] -= 1; // 记得减1...
    for(int i = 500; i >= 1; i--) {
        if(i % 50 == 0) cout << endl;
        cout << base[i];
    }
    return 0;
}