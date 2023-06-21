//快速幂+数论+二进制
#include<bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
 
int main(){
	int t;
	cin >> t;
	long long n, k;
	while(t--) {
		cin >> n >> k;
		long long ans = 0, cnt = 1;
		for(int i = 1; i <= 32; i++){
			if(k & 1){ //判断奇偶
				ans =(ans + cnt) % N;
			}
			cnt = (cnt * n) % N;
			k >>= 1;
		}
		cout << ans << endl;
	}
	return 0;

}
