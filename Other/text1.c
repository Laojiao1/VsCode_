#include <stdio.h>
int main() {
	char a[1001];
	char b[1001];
	int flag, i, j;
	int count = 0;
	for(i = 0; (a[i] = getchar()) != '\n'; i ++) {
		b[i] = a[i];
	}
	a[i] = 0;
	for(i = 0; a[i] != '\0'; i ++) {
		flag = 0;
		if(a[i] >= 'A' && a[i] <= 'Z') {
			for(j = 0; j < i; j ++) {
				if(b[j] == a[i]) {
					flag = 1;
				}
			}
			if(flag == 0) {
				printf("%c", a[i]);
				count ++;
			}
		}
	}
	if(count == 0) {
		printf("Not Found");
	}
	
	return 0;
}