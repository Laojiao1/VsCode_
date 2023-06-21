#include<bits/stdc++.h>
 
using namespace std;
const int MAX = 2e5 + 5;
int n,h;
int b[MAX],c[MAX];
struct Node {
	int l,r;
} node[MAX];
int main()
{
	cin>>n>>h;
	for(int i = 1; i<=n; i++) scanf("%d%d",&node[i].l,&node[i].r);
	c[1] = 0;b[1] = node[1].r-node[1].l;
	for(int i = 2; i<=n; i++) {
		b[i] = node[i].r - node[i].l;
		c[i] = node[i].l - node[i-1].r;
		b[i] += b[i-1];
		c[i] += c[i-1];
	}
	
	// cout << "b[i] = ";
	// for(int i = 1; i <=n ; i++) {
	// 	cout << b[i] << " ";
	// }
	// cout << endl;
	// cout << "c[i] = ";
	// for(int i = 1; i <=n ; i++) {
	// 	cout << c[i] << " ";
	// }
	// cout << endl;
	
	int maxx = -1,ans;
	for(int i = 1; i<=n; i++) {
		int pos = lower_bound(c+1,c+n+1,c[i]+h) - c;
		// cout << "pos = " << pos << endl;
		ans = b[pos-1] - b[i-1];
		maxx = max(maxx,ans);
	}
	printf("%d\n", maxx+h);
	return 0 ;
}