#include<stdio.h>
#include<string.h>
int main(){
	int i, j;
    char str1[5][80], temp[80];
    for(i = 0; i < 5; i++) {
        scanf("%s", str1[i]);
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4-i; j++) {
            if(strcmp(str1[j], str1[j+1]) > 0) {
                strcpy(temp, str1[j]);
                strcpy(str1[j], str1[j+1]);
                strcpy(str1[j+1], temp);
            }
        }
    }
    printf("After sorted:\n");
    for(i = 0; i < 5; i++) {
        printf("%s\n", str1[i]);
    }
    return 0;
} 
