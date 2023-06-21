#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
bool a[maxn], b[maxn];
int main() {
	int n, s;
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	if(a[1]==1 && (a[s]==1 || b[s]==1))
	{
		if(a[s] == 1) {
			cout << "YES";
			return 0;
		} else {
			for(int i = s+1; i <= n; i++) {
				if(a[i] == 1 && b[i] == 1) {
					cout<<"YES";
					return 0;
				}
            }
		}
	}
	cout << "NO";
	return 0;
}
