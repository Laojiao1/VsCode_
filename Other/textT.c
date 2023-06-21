#include <stdio.h>
#include <string.h>
int main() {
	char s[1001];
	gets(s);
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = 'A' + 'Z' - s[i];
		}
	}
	puts(s);
	return 0;
}