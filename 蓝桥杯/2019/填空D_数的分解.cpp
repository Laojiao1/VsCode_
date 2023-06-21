#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int num[4], ans1;
bool check(int n) {
    while(n) {
        int num = n % 10;
        n /= 10;
        if(num == 2 || num == 4) {
            return false;
        }
    }
    return true;
}
bool check1() {
    num[2] = 2019 - num[1] - num[0];
    int x = num[0];
    int y = num[1];
    int z = num[2];
    if(x==y||x==z||y==z||z<y) return false;
    for(int i = 0; i < 3; i++) {
        int n = num[i];
        while(n) {
        int num = n % 10;
        n /= 10;
        if(num == 2 || num == 4) {
            return false;
        }
    }
    }  
    return true;
}

void dfs(int u, int st) {
    if(u == 2) {
        if(check1()) {
            ans1++;
        }
        return;
    }
    for(int i = st; i < 2019; i++) {
        num[u] = i;
        dfs(u+1, i+1);
    }
} 
int main() {
    int ans = 0;
    for(int i = 1; i < 2019; i++) {
        if(check(i)) {
            for(int j = i + 1; j < 2019; j++) {
                if(check(j)) {
                    int k = 2019-i-j;
                    if(k > j && check(k)) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    dfs(0, 1);
    cout << ans1 << endl;
    return 0;
}