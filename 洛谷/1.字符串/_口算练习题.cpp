//总结:
//isalpha() 判断一个字符是否为字母
//atoi() 把ss字符串转换为一个整数（int）

#include <bits/stdc++.h>
using namespace std;
int n, x, y;
char s[20], ans[100], k;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", &s);
		if(isalpha(s[0])) { //isalpha()判断一个字符是否为字母
			k = s[0];
			scanf("%d %d", &x, &y);
		} else {
			x = atoi(s); //把ss字符串转换为一个整数（int）
			scanf("%d", &y);
		}
		if(k == 'a')
			sprintf(ans,"%d+%d=%d", x, y, x+y);
		else if(k == 'b')
			sprintf(ans,"%d-%d=%d", x, y, x-y);
		else
			sprintf(ans,"%d*%d=%d", x, y, x*y);
		printf("%s\n%d\n", ans, strlen(ans));
	}
	return 0;
}