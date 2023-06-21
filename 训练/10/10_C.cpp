#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
int main()
{
	cin >> t;
	while(t--) {
		cin >> n;
		ll sum = 0;
		while(n) {
			sum += n/1;
			n >>= 1;
		}
		cout << sum << endl;
	}
}
