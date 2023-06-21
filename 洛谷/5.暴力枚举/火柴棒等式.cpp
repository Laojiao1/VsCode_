// P1149 https://www.luogu.com.cn/problem/P1149
// 巧妙的思路
// 只需要按照取值范围把0-2000内的数表示出来就可以
// 注意特判 a[0] = 6;
#include <bits/stdc++.h>
using namespace std;
int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[2001] = {6}; // a[0] = 6 特判
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= 2000; i++) { // 把1-2000数所需的火柴棒全部表示出来
        int num = i;
        while(num >= 1) {
            a[i] = a[i] + f[num%10];
            num = num/10;
        }
    }
    // 枚举每一个数
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            if(a[i] + a[j] + a[i+j] + 4 == n) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}