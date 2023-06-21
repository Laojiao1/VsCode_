#include <bits/stdc++.h>
using namespace std;
int n, m, heap[1001];
int cnt = 0;
void create(int num) {
    heap[++cnt] = num;
    int t = cnt;
    while(t > 1 && heap[t] < heap[t/2]) {
        heap[t] = heap[t/2];
        heap[t/2] = num;
        t /= 2;
    }
    heap[t] = num;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;

    }
    return 0;
}