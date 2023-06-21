// P1088 https://www.luogu.com.cn/problem/P1088
// 是个好题，但我只会STL...
// 隔一段时间再来看这道题吧。
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10001];
inline int read()
{
    int re = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch >= '0' && ch<='9') {re=re*10+(ch-'0'); ch=getchar();}
    return re*f;
}
int main() {
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) next_permutation(a+1, a+1+n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}