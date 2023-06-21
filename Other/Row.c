#include <stdio.h>
#define len 50005
int main() {
    int n, i, j, k, min, max;
    int temp, temp1;
    int a[len];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    min = max = a[0];
    for(i = 0; i < n; i++) {
        if(a[i] <= min) {
            min = a[i];
            j = i;
        }
    }
    temp = a[0];
    a[0] = min;
    a[j] = temp;
    for(i = 0; i < n; i++) {
        if(a[i] >= max) {
            max = a[i];
            k = i;
        }
    }
    temp1 = max;
    a[k] = a[n-1];
    a[n-1] = temp1;
    for(i = 0; i < n; i++)  {
        printf("%d ", a[i]);
    }
    return 0;
}