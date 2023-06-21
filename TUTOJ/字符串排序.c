#include<stdio.h>
#include<string.h>
int main() {
	char a[5][80];
	char s[80];
  	int i, j;
	for(i = 0; i < 5; i++){
		scanf("%s", a[i]);
	}
	for(i = 0; i < 5; i++) {
		for(j = 0; j<(4-i); j++) {
			if( a[j] > a[j+1] ) {
				strcpy(s, a[j]);
				strcpy(a[j], a[j+1]);
				strcpy(a[j+1], s);
			}
		}
	}
  	printf("After sorted:\n");
	for(i = 0; i < 5; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}