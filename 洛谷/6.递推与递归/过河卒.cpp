// f[i][j] = f[i][j-1] + f[i-1][j];
#include <bits/stdc++.h>
using namespace std;
long long mp[30][30];
bool mp1[30][30];
int x, y, x2, y2; //分别表示B点坐标和马坐标
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int main() {
    cin >> x >> y >> x2 >> y2;
    x += 2; x2 += 2; y += 2; y2 += 2;
    mp[2][1] = 1;// 初始化
    mp1[x2][y2] = 1;
    for(int i = 1; i <= 8; i++) {
        mp1[x2 + fx[i]][y2 + fy[i]] = 1;
    }
    for(int i = 2; i <= x; i++) {
        for(int j = 2; j <= y; j++) {
            if(mp1[i][j]) continue;
            mp[i][j] = mp[i-1][j] + mp[i][j-1];
        }
    }
    cout << mp[x][y] << endl;
    return 0;
}