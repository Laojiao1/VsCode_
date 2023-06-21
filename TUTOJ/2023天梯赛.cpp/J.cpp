#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1010, M = 2010;
queue<int> q;
int n;
int a[N];
int b[N];
int main ()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		b[i] = i;
		q.push(i);
	}
	
	while(q.size()){
		int t = q.front();
		a[t] --;
		if(a[t]){
			b[t] += q.size();
		}
		q.pop();
		if(a[t])q.push(t);
	}
	for(int i = 1; i <= n; i ++){
		printf("%d ",b[i]);
	}
	
	return 0;
}