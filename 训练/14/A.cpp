#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int n, a[MAX];
bool vis[MAX];
int main()  {
	cin >> n;	
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int b = i;
		memset(vis, 0, sizeof(vis));
		while(1) {
			if(vis[b]) break;
			vis[b] = 1;
			b = a[b];
		}
		cout << b << " ";
	}
	return 0 ;
}