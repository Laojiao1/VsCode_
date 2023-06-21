// 记忆化优先搜索
#include <bits/stdc++.h>
using namespace std;
int a = 1, b = 1, c = 1;
#define Func(x, y, z) (f[x][y][z] ? f[x][y][z] : f[x][y][z] = w(x, y, z))
int f[25][25][25];
int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a > 20 || b > 20 || c > 20) return Func(20,20,20);
    if(a < b && b < c) return Func(a,b,c-1)+Func(a,b-1,c-1) - Func(a,b-1,c);
    return Func(a-1,b,c)+Func(a-1,b-1,c)+Func(a-1,b,c-1) - Func(a-1,b-1,c-1);
}
int main() {
    ios::sync_with_stdio(false);
    while(1) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}