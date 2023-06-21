#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
void Reverse(char str[]);
int main() {
	char str[50];
	gets(str);
	Reverse(str);
	printf("%s\n", str);
	
	return 0;
}

void Reverse(char scr[]) {
	int i;
	int n;
	int temp;
	n = strlen(scr);
	for (i = 0; i < (n/2); i++) {
		temp = scr[i];
		scr[i] = scr[n-1-i];
		scr[n-1-i] = temp;
	}
}
