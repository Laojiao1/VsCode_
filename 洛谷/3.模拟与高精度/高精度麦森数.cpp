// P1045
// 快速幂进行优化
// 我们知道10^k有k+1位，而k=lg(10^k)。所以2^p的位数是lg(2^p)+1=p*lg(2)
// 下面解决500位求值的问题：
// 开一个a[501]long long数组，
// 记为ull，然后还是用每个元素表示1位数，
// 每次乘一轮不要乘2，乘2^60（9乘以2的60次方刚好不会溢出），
// 记得把p多减掉59就行了。
// 代码：
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[501] = {1};
int main() {
	int p;
	cin >> p;
	cout << (int)(p*log10(2)) + 1 << endl;//log10才是以十为底的对数
	for( ; p > 0; p -= 60) { //每次减掉60次幂
		ll f = 0;//进位
		for(int i = 0 ; i < 500; i++) {
			if(p > 60) a[i] <<= 60; //每一轮乘2^60
			else a[i] <<= p; //如果剩下的不够60了就不要乘60了，乘p
			a[i] += f;
			f = a[i]/10;
			a[i] %= 10;
		}
	}
	a[0] -= 1;//千万不要忘记减1，否则你会和我第一次一样WA掉全部
	for(int i = 499; i >= 0; i--) {
		cout << a[i] + '0';
		if(i % 50 == 0) cout << endl;
	}
	return 0;
}

// 以下算法会超时！！！！

// #include <bits/stdc++.h>
// using namespace std;
// long long P;
// const int maxn = 50005;
// int a[maxn], b[maxn], ans[maxn];
// string mul(string s1, string s2) {
//     memset(a, 0, sizeof(a));
//     memset(b, 0, sizeof(a));
//     memset(ans, 0, sizeof(a));
//     int len_a, len_b, len_ans;
//     string ret;
//     len_a = s1.length();
//     len_b = s2.length();
//     len_ans = len_a + len_b;
//     for(int i = 1, j = len_a-1; i <= len_a; i++, j--) {
//         a[i] = s1[j] - '0';
//     }
//     for(int i = 1, j = len_b-1; i <= len_b; i++, j--) {
//         b[i] = s2[j] - '0';
//     }
//     for(int i = 1; i <= len_a; i++) {
//         for(int j = 1; j <= len_b; j++) {
//             ans[i+j-1] += a[i] * b[j];
//             ans[i+j] += ans[i+j-1] / 10;
//             ans[i+j-1] %= 10;
//         }
//     }
//     while(len_ans > 1 && ans[len_ans] == 0) len_ans--;
//     while(len_ans >= 1) ret += ans[len_ans--] + '0';
//     return ret;
// }   
// int main() {
//     cin >> P;
//     string sum = "1";
//     int s = 2;
//     for(int i = 1; i <= P; i++) {
//         sum = mul(sum, to_string(s));
//     }
//     int len = sum.length();
//     cout << len << endl;
//     sum[len-1] -= 1;
//     int cnt1 = 0, cnt2 = 0, cnt = 0;
//     if(len > 500) {
//         int pos = len - 501;
//         for(int i = 1; i <= 500; i++) {
//             cout << sum[pos++];
//             if(i % 50 == 0) cout << endl;
//         }
//     } else if (len < 500) {
//         int pos = 499-len;
//         for(int i = 0; i < 500; i++) {
//             if(i <= pos) cout << '0';
//             else cout << sum[cnt++];
//             cnt1++;
//             if(cnt1 % 50 == 0) cout << endl;
//         }
//     } else if(len == 500) {
//             for(int i = 0; i < 500; i++) {
//                 cout << sum[i];
//                cnt2++
//                if(cnt2 % 50 == 0) cout << endl;
//            }
//        }
//     return 0;
// }