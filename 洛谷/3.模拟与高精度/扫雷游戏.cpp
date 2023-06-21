#include <bits/stdc++.h>
using namespace std;
bool mp[101][101]; //有地雷为1，无地雷为0
int main() {
    int n, m;
    char a;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a;
            if(a == '*') mp[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j] == 1) cout << '*';
            else {
                cout << mp[i-1][j] + mp[i+1][j] + mp[i][j-1] + mp[i][j+1]
                      + mp[i-1][j-1] + mp[i+1][j+1] + mp[i-1][j+1] + mp[i+1][j-1]; 
            }
        }
        cout << endl;
    }
    return 0;
}