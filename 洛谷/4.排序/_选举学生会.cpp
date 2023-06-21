// P1271
// 简单的排序
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 2e6+2;
int a[maxn];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+m);
    for(int i = 1; i <= m; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;
    return 0;
}

// 思路二，桶排
// 用1001的数组记录票出现的次数，最后根据票出现的次数输出即可
// #include<bits/stdc++.h>
// using namespace std;
// int a,n,m,b[1000];
// int main() {
// 	cin >> n >> m;
// 	for(int i = 1; i <= m; i++) cin >> a, ++b[a]; //记录票出现的次数
// 	for(int i = 1; i <= 1000; i++) {
//         while(b[i]--)
//             cout << i << " "; //根据票出现的次数输出
//     }
//     return 0;
// }