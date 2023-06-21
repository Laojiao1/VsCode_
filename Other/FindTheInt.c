#include <stdio.h>
int main() {
    int  n, m;
    int i, temp = 0;
    int cnt = 0;
    int a[50005];
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++) {
        if(a[i] == m) {
            cnt = i;
            temp = 1;
        } else {
            continue;
        }
    }
    if(temp == 1) {
        printf("%d", cnt);
    } else {
        printf("Not Found");
    }
    return 0;
}