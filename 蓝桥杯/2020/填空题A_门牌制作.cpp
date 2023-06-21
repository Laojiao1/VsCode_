// 签到题
#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    for(int i = 1; i <= 2020; i++) {
        int num = i;
        while(num != 0) {
            int temp = num % 10;
            if(temp == 2) ans++;
            num /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}