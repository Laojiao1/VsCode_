// 求一个区间内最大值和最小值的差
// https://www.luogu.com.cn/problem/P2880
// ST表板子题
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
int Max[N][21], Min[N][21];
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int Query(int l, int r) {
    int j = log2(r - l + 1);
    int a = max(Max[l][j], Max[r-(1<<j)+1][j]);
    int b = min(Min[l][j], Min[r-(1<<j)+1][j]);
    return a - b;
}
int main() {
    // freopen("in.in", "r", stdin);
    int n, m;
    n = read(), m = read();
    for(int i = 1; i <= n; i++) {
        Max[i][0] = Min[i][0] = read();
    }
    for(int j = 1; j <= 21; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) {
            Max[i][j] = max(Max[i][j-1], Max[i+(1<<(j-1))][j-1]);
            Min[i][j] = min(Min[i][j-1], Min[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        a = read(), b = read();
        printf("%d\n", Query(a, b));
    }
    return 0;
}