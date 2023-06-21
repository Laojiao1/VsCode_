// https://www.luogu.com.cn/problem/P1017
// 负进制
#include <bits/stdc++.h>
using namespace std;
int n, jz;
void func(int num, int jz) {
    if(num == 0) return;
    int temp = num % jz;
    if(temp < 0) {
        temp -= jz; // 把商变成正数
        num += jz; // 因为余数减去了一个jz, 所以num要加上一个jz
    }
    if(temp >= 10) temp = temp + 'A' - 10; // 如果大于10的话就转换一下字符
    else temp += '0'; // 否则就转换为字符，方便输出
    func(num/jz, jz); // 函数递归
    printf("%c", temp);
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> jz;
    cout << n << "=";
    func(n, jz);
    printf("(base%d)", jz);
    return 0;
}