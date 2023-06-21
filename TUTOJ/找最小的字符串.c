#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char a[n][81];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    char b[81];
    strcpy(b, a[0]);
    for(i = 1; i < n; i++) {
        if(strcmp(a[i], b) < 0) {
            strcpy(b, a[i]);
        }
    }
    printf("The longest is: %s\n", b);
    return 0;
}