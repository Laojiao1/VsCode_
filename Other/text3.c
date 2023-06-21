
#include <stdio.h>
struct box{
	int date;
	int num;
	int f;
} B[1001];
int main() {
	int n;
	int sum = 0;
	int num = 1;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &B[i].date);
		B[i].f = 0;
	}
	int m = n;
	while (m) {
		for(i = 0; i < n; i++) {
			if(B[i].f == 0) {
				sum += B[i].date;
			  	if(sum <= 100) {
					B[i].f = 1;
					B[i].num = num;
					m --;
				} else {
				sum -= B[i].date;
				}
			}
		}
		num ++;
		sum = 0;
	}
	for(i = 0; i < n; i++) {
		printf("%d %d\n", B[i].date, B[i].num);
	}
	printf("%d\n", num - 1);
	return 0;
}