// P2415
// 数学题
// 求一个集合s中所有子集元素之和
// 结论： ans = （集合中每一个元素之和）* 2^(n-1)
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    int cnt = 0;
    int i, a;
    while(scanf("%d", &a) != EOF) {
        ans += a;
        cnt++;
    }
    for(int i = 1; i < cnt; i++) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}