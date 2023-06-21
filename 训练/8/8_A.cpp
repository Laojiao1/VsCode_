#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int cnt1, cnt2;
int a[maxn];
int n;
int b;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int temp = 0;
    if(a[0] == 1) {
        cnt1++;
    } else {
        cnt2 ++;
    }
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1]) temp++; //记录分界点
        if(temp == 2) {
            b = max(b, min(cnt1, cnt2));
            if(a[i] == 1) cnt1 = 0;
            else cnt2 = 0;
            temp = 1;
        }
        if(a[i] == 1) cnt1++;
        else cnt2++;
    }
    b = max(b, min(cnt1, cnt2));
    printf("%d\n", 2*b);
    return 0;
}