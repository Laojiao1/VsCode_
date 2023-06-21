// 我们默认tag = 1，对于tag = 2的情况将N1，N2交换即可。
// 对于可能的进制数，其区间为[N2各位中最大的数+1，N2+1]。我们使用二分查找来寻找答案。
// 由于数据过大，查找过程中数据可能溢出，溢出时将N2转换为进制数结果是负数
// （我们知道无论是多少进制都是不可能转化成负数的，所以可知结果是负数代表结果是一个超过long long的大正数）
#include <bits/stdc++.h>
using namespace std;
long long convert(string n, long long radix) {
	long long base = 1, num = 0;
	for(auto it = n.rbegin(); it != n.rend(); it++) { // 倒着遍历字符串 
		int temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		num += temp * base;
		base *= radix;
	}
	return num;
}
int main() {
    //freopen("in.in", "r", stdin);
	string n1, n2;
	int tag;
	long long radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag == 2) {
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}	
	long long num = convert(n1, radix); // 转换为10进制 
	char it = *max_element(n2.begin(), n2.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(low, num) + 1;
	long long mid;
	bool flag = 0; 
	while(low <= high) {
		mid = (low + high) / 2;
		long long res = convert(n2, mid);
		if(res < 0 || res > num) { // 注意 数据有可能溢出，溢出的情况下res < 0 
			high = mid - 1;
		} else if(res < num) {
			low = mid + 1;
		} else {
			low = mid;
			flag = 1;
			break; 
		}
	}
	if(flag) {
		cout << low << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}