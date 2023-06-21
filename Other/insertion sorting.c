#include <stdio.h>
int main() {
    int arr[50005];
    int n, i, j;
    int cnt;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int number;
    scanf("%d", &number);
    for(i = 0; i < n; i++) {
        if(arr[i] > number) {
            break;
        }
    }
    for(j = n-1; j >= i; j--) {
        arr[j + 1] = arr[j];
    }
    arr[i] = number;
    for(i = 0; i < n+1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}