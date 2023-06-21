#include<bits/stdc++.h>
using namespace std;

int a[1010][1010];
struct hyq{
	int x;
	int y;
}h[10001000];

int main(){

	int n;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			cin >> a[i][j];
			h[a[i][j]].x = i ;
			h[a[i][j]].y = j ;	
		}
	}
	n = n*n ;
	for(int i = 2 ; i <= n ; i++){
		cout << h[i].y - h[i-1].y << " " << h[i].x - h[i-1].x << endl;
	}
	
	
}