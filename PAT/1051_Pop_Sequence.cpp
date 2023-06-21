// 栈模拟
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        bool flag = 0;
        stack<int> s;
        vector<int> v(n+1);
        for(int j = 1; j <= n; j++) {
            scanf("%d", &v[j]);
        }
        int cur = 1; // 栈
        for(int j = 1; j <= n; j++) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[cur]) {
                s.pop();
                cur++;
            }
        }
        if(cur == n+1) flag = 1;
            if(flag == 1) printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}