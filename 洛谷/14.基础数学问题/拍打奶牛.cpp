// https://www.luogu.com.cn/problem/P2926
// a[i] / j = i; -> i*j = a[i]
// 于是开始枚举
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N], b[N], cnt[N], n;
void func() {
    for(int i = 1; i <= N; i++) {
        if(!b[i]) continue;
        for(int j = 1; j*i <= N; j++) { // 枚举除数
            if(b[j*i]) cnt[i*j] += b[i];
            if(j*i == i) cnt[i*j]--; // 排除掉拍自己的头
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    func();
    for(int i = 1; i <= n; i++) {
        cout << cnt[a[i]] << endl;
    }
    return 0;
}