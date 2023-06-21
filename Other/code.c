#include<stdio.h>
#include<math.h>
int main()
{
	int a[80] = {0};
	char ch;
	int n = 1;	//n表示数组下标，从1开始
	int s = 0; 	//s表示十进制结果
	while((ch = getchar()) != '#') {
		if(ch >= 48 && ch <= 57) {		//字符'0'到'9'
			a[n] = (int)ch - 48;
			n ++;
		} else if(ch >= 65 && ch <= 70) {	//字符'A'到'F'
			a[n] = (int)ch - 55;
			n ++;
		} else if(ch >= 97 && ch <= 102) {	//字符'a'到'f'
			a[n] = (int)ch - 87;
			n ++;
		} else if(ch == '-' && n == 1) {    //判断负号
			a[0] = -1;		//a[0]表示负号
		} else {
            continue;
	    }
    }
	n --; 
	for(int i = 0; n > 0; --n, ++i) {
		s += a[n] * pow(16,i);
	}
	if(a[0] == -1) {
        s *= -1;
    }
	printf("%d\n",s);
	return 0;
}