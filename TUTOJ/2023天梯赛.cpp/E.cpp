#include <bits/stdc++.h>
using namespace std;
const int Maxn=10005;
int N,L,P;
int A[Maxn],B[Maxn];
void solve(){
    A[N]=L;
    B[N]=0;
    priority_queue<int> que;
    int ans=0,pos=0,tank=P;
    for(int i=0;i<=N;i++){
        int d=A[i]-pos;
        while(tank<d){
            if(que.empty()){
                puts("-1");
                return;
            }
            tank+=que.top();
            que.pop();
            ans++;
        }
        pos=A[i];
        tank-=d;
        que.push(B[i]);
    }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d %d %d",&N,&L,&P);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&B[i]);

    solve();
    return 0;
}
