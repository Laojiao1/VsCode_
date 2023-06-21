#include <stdio.h>
int main()
{
	char s1[80], s2[80] = {0};
	int i, j ,k = 0;
	int flag = 0;
	gets(s1);
	for(i = 0; s1[i] != '\0'; i++) {
		if(s1[i] >= 'A' && s1[i] <= 'Z') {
			flag = 1;
			for(j = 0; j < k; j++) {
			    if(s1[i] == s2[j])
			        break; 
            }
			if(j >= k) {
				s2[k] = s1[i];
				k ++;
			}
		}
	}
	if(flag == 0)
	    printf("Not Found");
	else
	    puts(s2);
	return 0;
}