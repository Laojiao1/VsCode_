// 模拟映射题
#include <bits/stdc++.h>
using namespace std;
const int N = 54;
char t[5] = {'S', 'H', 'C', 'D', 'J'};
int cur[N], tran[N];
int main() {
    //freopen("in.in", "r", stdin);
    int next[N];
    int T;
    cin >> T;
    for(int i = 0; i < N; i++) {
        cin >> tran[i];
        tran[i]--;
    }
    for(int i = 0; i < N; i++) {
        cur[i] = i;
    }
    while(T--) {
        for(int i = 0; i < N; i++) {
            next[tran[i]] = cur[i];
        }
        for(int i = 0; i < N; i++) {
            cur[i] = next[i];
        }
    }
    printf("%c%d", t[cur[0] / 13], cur[0] % 13 + 1);
    for(int i = 1; i < N; i++) {
        printf(" %c%d", t[cur[i] / 13], cur[i] % 13 + 1);
    }
    return 0;
}