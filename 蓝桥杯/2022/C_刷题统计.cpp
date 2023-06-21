// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll a, b, n, ans;
// ll sum, week, weekend;
// ll func(int n) {
//     ll temp = 0;
//     if(n == 0) {
//         return 0;
//     }
//     if(n < a) {
//         temp = 1;
//         return temp;
//     }
//     if(week >= n) {
//         if(n % a == 0) {
//             temp = n / a;
//         } else {
//             temp = (n / a) + 1;
//         }
// 	} else {
//         if(n - week < b) {
//             temp = 6;
//             return temp;
//         }
//         if((n - week) % b == 0) {
//             temp = 5 + (n - week) / b;
//         } else {
//             temp = 6 + (n - week) / b;
//         }
// 	}
//     return temp;
// }
// int main() {
// 	scanf("%lld %lld %lld", &a, &b, &n);
// 	week = 5*a;
// 	weekend = 2*b;
// 	sum = 5*a + 2*b;
// 	if(sum > n) {
// 		ans = func(n);
// 	} else {
// 		int cnt = n / sum;
//         if(n % sum == 0) {
//             ans = cnt * 7;
//         } else {
//             ans = cnt * 7 + func(n - cnt*sum);
//         }
// 	}
// 	printf("%lld\n", ans);
// 	return 0;
// } 
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long a,b,n;
//     long long ans=0,sum=0;
//     scanf("%lld%lld%lld",&a,&b,&n);
//     ans+=n/(5*a+b*2);
//     sum=ans*7;
//     if((n-(a*5+b*2)*ans)<=5*a)
//     {
//         sum+=(n-(5*a+2*b)*ans)/a;
//         if((n-(5*a+2*b)*ans)%a!=0)
//         {
//             sum++;
//         }
//     }
//     else
//     {
//         sum+=5;
//         sum+=((n-(5*a+2*b)*ans)-5*a)/b;
//         if(((n-(5*a+2*b)*ans)-5*a)%b!=0)
//         {
//             sum++;
//         }
//     }
//     printf("%lld",sum);
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, n;
    ll ans = 0, day = 1, sum = 0;
    cin >> a >> b >> n;
    while(sum < n) {
        day %= 7;
        if(day >= 1 && day <= 5) {
            sum += a;
        } else if(day == 6 || day == 0){
            sum += b;
        }
        day++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}