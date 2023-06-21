#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#define rep(i,x,y) for(register int i = x ; i <= (y); ++ i)
#define repd(i,x,y) for(register int i = x ; i >= (y); -- i)
#define abs(x) (x > 0 ? x : -(x))
using namespace std;
typedef long long ll;
template<class T>inline bool chkmax(T&a,T b) { return a < b ? a = b,1:0; }
template<typename T> inline void read(T&x)
{
    x = 0;char c;int sign = 1;
    do { c = getchar();if(c == '-') sign = -1; }while(c < '0' || c > '9');
    do { x = x * 10 + c - '0'; c = getchar(); }while(c <= '9' && c >= '0');
    x *= sign;
}

const int N = 1e5 + 500,M = 3e5+500;
int n,k,d[N],vised[M];
int tot,head[N],w[M],nxt[M],to[M];
ll num;
bool vis[N];
queue<int>q;

inline void add(int a,int b,int c)
{
    w[tot] = c;
    nxt[tot] = head[a];
    to[tot] = b;
    head[a] = tot++;
}

inline bool SPFA()
{
    q.push(0);
    while(!q.empty())
    {
        int x = q.front();q.pop();vis[x] = 0;
        for(register int i = head[x];~i; i = nxt[i])
        if(chkmax(d[to[i]],d[x] + w[i]) )
        {
            vised[i] ++;
            if(vised[i] > n){
                puts("-1");
                return false;
            }
            if(!vis[to[i]])
                vis[to[i]] = 1,q.push(to[i]);
        }
    }
    return true;
}

int main()
{
    memset(head,-1,sizeof head);
    read(n);read(k);
    
    int op,u,v;
    rep(i,1,k)
    {
        read(op);read(u);read(v);
        if(op == 1) add(u,v,0),add(v,u,0);
        if(op == 2) add(u,v,1);
        if(op == 3) add(v,u,0);
        if(op == 4) add(v,u,1);
        if(op == 5) add(u,v,0);
        if(!(op&1) && u == v) return puts("-1"),0;
    }
    
    repd(i,n,1)
    add(0,i,1);
    
    if(!SPFA()) return 0;
    
    repd(i,n,1)
    num += d[i];
    printf("%lld",num);
    return 0;
}