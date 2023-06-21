// P1591
// 高精度好题
#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main() {
    int t;
    cin >> t;
    while(t--) {
        a[1] = 1;
        int n, m;
        int j;
        cin >> n >> m;
        int pos = 1, jw = 0; //位数、进制
        for(int i = 2; i <= n; i++) {
            jw = 0;
            for(j = 1; j <= pos; j++) {
                a[j] = a[j]*i + jw;
                jw = a[j] / 10; // 处理进制
                a[j] = a[j] % 10; // 处理进位
            }
            // 如果还有进制的话
            while(jw > 0) {
                a[j] = jw % 10;
                jw /= 10;
                j++;
            }
            pos = j-1;
        }
        long long cnt = 0;
        for(int i = pos; i >= 1; i--) {
            if(a[i] == m) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}