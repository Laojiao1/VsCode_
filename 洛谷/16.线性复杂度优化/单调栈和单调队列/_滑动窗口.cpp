// 依旧是单调队列模板题
// https://www.luogu.com.cn/problem/P1886
// 用优先队列实现单调队列，但是所耗时间和空间较大
#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
typedef pair<int, int> p;
priority_queue<p, vector<p>, less<p> > q1;
priority_queue<p, vector<p>, greater<p> > q2;
int n, k;
long long arr[N];
inline int rd() // 快读
{
    int data = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0'&&ch <= '9')
    {
        data = (data<<3) + (data<<1) + ch - '0';
        ch = getchar();
    }
    return f * data; 
}
int main() {
    freopen("in.in", "r", stdin);
    n = rd(), k = rd();
    for(int i = 1; i <= n; i++) {
        arr[i] = rd();
    }
    for(int i = 1; i <= n; i++) {
        q2.push(make_pair(arr[i], i));
        if(i - k >= 0) {
            while(q2.top().second <= i - k) q2.pop();
            printf("%d", q2.top().first);
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        q1.push(make_pair(arr[i], i));
        if(i - k >= 0) {
            while(q1.top().second <= i - k) q1.pop();
            printf("%d", q1.top().first);
        }
    }
    return 0;
}