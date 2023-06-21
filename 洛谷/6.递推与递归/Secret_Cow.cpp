// P3612 https://www.luogu.com.cn/problem/P3612
// 递推
#include <bits/stdc++.h>
using namespace std;
long long n;
long long len, i;
string s;

int main() {
    cin >> s >> n;
    len = s.length();
    while(len < n) {
        i = len;
        while(n > i) i *= 2; // 求出当前刚好包含n位置的串长
        i = i/2; //得到当前串的一半长度
        n = n - i - 1; // 推出来的公式规律
        // if(n == i + 1) { 
        //     n = i;
        // }
        // 特殊处理，相当于到了复制时候的边界
        // 但要注意不能写成(n == i-1)
        // 因为如果这样的话 0 就被忽略了
        // 因此要这样写
        if(n == 0) n = i; 
    }
    cout << s[n-1] << endl;
    return 0;
}