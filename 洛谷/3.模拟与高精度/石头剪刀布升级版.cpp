// P1328
// 纯纯模拟题 直接打表
// 遇到周期性问题利用取模
#include <bits/stdc++.h>
using namespace std;
int A[201], B[201];
int score_a, score_b;
int mp[5][5] = {
                    {0, 0, 1, 1, 0},
                    {1, 0, 0, 1, 0},
                    {0, 1, 0, 0, 1},
                    {0, 0, 1, 0, 1},
                    {1, 1, 0, 0, 0}
               };

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < n; i++) {
        score_a += mp[A[i % a]][B[i % b]];
        score_b += mp[B[i % b]][A[i % a]];
    }
    cout << score_a << " " << score_b << endl;
    return 0;
}