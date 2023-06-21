#include <stdio.h>
int main(){
    int i;
    int length = 0, index = -1;
    char a, str[1000];
    int ch;
    scanf("%c\n", &a);
    ch = getchar();
    for(i = 0; ch != '\n'; i++) {
        str[i] = ch;
        length ++;
        ch = getchar();
    }
    for(i = 0; i < length; i++) {
        if(a == str[i]) {
            index = i;
        }
    }
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    return 0;
}