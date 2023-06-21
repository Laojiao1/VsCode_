#include<stdio.h>
int main()
{
    int n, i, a[300][300], j;
    scanf("%d", &n);
    for(i = 0; i < n ; i++)
        for(j = 0; j < n; j ++)
            a[i][j] = 0; 

    for(i = 0; i < n; i++)
        a[i][0] = 1;

    for(i = 0; i < n; i++)
        for(j = 1; j < i+1; j++)
            a[i][j] = a[i-1][j] + a[i-1][j-1];

    for(i = 0; i < n; i++)
    {
        for(j = n-1-i; j > 0; j--)
            printf(" ");
        for(j = 0;j < i+1; j++)
            printf("%4d", a[i][j]);
        printf("\n");
        
    }
        
    return 0;
}
