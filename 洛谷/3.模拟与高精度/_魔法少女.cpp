// P4924
// 矩阵顺逆旋转
#include <bits/stdc++.h>
using namespace std;
int mp[501][501], temp[501][501];
int n, m;

void spin(int x, int y, int r, int z) {
    if(z == 0) {
        for(int i = x-r; i <= x+r; i++) {
            for(int j = y-r; j <= y+r; j++) {
                temp[i][j] = mp[i][j];
            }
        } // 先把目标矩阵抠出来
        int x1 = x + r;
        int y1 = y - r;
        for(int i = x-r; i <= x+r; i++) {
            for(int j = y-r; j <= y+r; j++) {
                mp[i][j] = temp[x1][y1];
                x1--;
            }
            x1 = x+r, y1++; //一列一列的搬
        }
    }
    // 同理
    if(z == 1) {
        for(int i = x-r; i <= x+r; i++) {
            for(int j = y-r; j <= y+r; j++) {
                temp[i][j] = mp[i][j];
            }
        } // 先把目标矩阵抠出来
        int x2 = x - r;
        int y2 = y + r;
        for(int i = x-r; i <= x+r; i++) {
            for(int j = y-r; j <= y+r; j++) {
                mp[i][j] = temp[x2][y2];
                x2++;
            }
            y2--, x2 = x-r; //一列一列的搬
        }
    }
}

int main() {
    cin >> n >> m;
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            temp ++;
            mp[i][j] = temp;
        }
    }
    int x, y, z, r;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> z >> r;
        spin(x, y, z, r);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}