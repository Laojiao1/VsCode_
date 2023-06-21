// 水题，映射即可
#include <bits/stdc++.h>
using namespace std;
string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void f(int n) {
	int num = n / 10;
	if(num > 0) {
		f(num);
		cout << " ";
	}
	cout << a[n % 10];
}
int main() {
	int n = 0;
	string s;
	cin >> s;
	long long len = s.size(); 
	for(int i = 0; i < len; i++) {
		n += s[i] - '0';
	} 
	if(n == 0) cout << "zero" << endl;
	else {
		f(n); // 递归输出 
	}
	return 0;
}