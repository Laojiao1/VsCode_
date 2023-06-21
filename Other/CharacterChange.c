#include<stdio.h>
int main(void)
{
    char a[80];
    char ch = '0';
    int i = 0, j;
    while(ch != '\n'){
        scanf("%c", &ch);
        a[i++] = ch;        
    }   
    for(j = 0; j < i-1; j ++){
        if(a[j] >= 'A' && a[j] <= 'Z')
                a[j] = 'A' + 'Z' - a[j];
        printf("%c", a[j]); 
    }   
    return 0;
}