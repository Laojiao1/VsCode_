// 水题
// 但这道题第一篇题解挺好，以后水平到了可以再去看看
#include <bits/stdc++.h>
using namespace std;
int n, s;
int a, b, h;
int cnt = 0;
struct Node {
    int height;
    int power;
} N[5001];
bool cmp(Node a1, Node a2) {
    return a1.power < a2.power;
}
int main() {
    cin >> n >> s;
    cin >> a >> b;
    h = a + b;
    for(int i = 1; i <= n; i++) {
        cin >> N[i].height >> N[i].power;
    }
    sort(N+1, N+1+n, cmp);
    // for(int i = 1; i <= n; i++) {
    //     cout << N[i].height << " " << N[i].power << endl;
    // }
    for(int i = 1; i <= n; i++) {
        if(N[i].height <= h && N[i].power <= s) {
            s -= N[i].power;
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}