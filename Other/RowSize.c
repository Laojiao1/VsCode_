#include <stdio.h>
#define len 50005
int main() {
    int n, i, j, temp;
    int a[len];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }
    return 0;
}
