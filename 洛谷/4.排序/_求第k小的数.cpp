// P1923 
// 用快排就可以
// 也可以选择使用STL中的nth-element函数
// 这个函数主要用来将数组元素中第k小的整数排出来并在数组中就位，
// 随时调用，可谓十分实用。
// 函数语句：nth_element(数组名,数组名+第k小元素,数组名+元素个数)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a[5000010];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    nth_element(a, a+k, a+n);
    printf("%d\n", a[k]);
    return 0;
}