// P1518
// 又是一道纯纯模拟题
// 判断是否进入死循环的小技巧：设置 "特殊值"
#include <bits/stdc++.h>
using namespace std;
char mp[12][12];
int f[3], c[3], ans, t; // 数组第0位代表方向：0：北，1：东，2：南，3：西
bool xh[200005];
void move(int x, int y, int mi, int h) { // 坐标、方向、角色(0:农夫, 1:奶牛)
    if(mi == 0) { // 北
        if(mp[x-1][y] == '*') {
            if(h == 0) f[0] = 1;
            else c[0] = 1;
        } else {
            if(h == 0) f[1] --;
            else c[1]--;
        }
    } else if(mi == 1) { // 东
        if(mp[x][y+1] == '*') {
            if(h == 0) f[0] = 2;
            else c[0] = 2;
        } else {
            if(h == 0) f[2]++;
            else c[2]++;  
        }
    } else if(mi == 2) { // 南
        if(mp[x+1][y] == '*') {
            if(h == 0) f[0] = 3;
            else c[0] = 3;
        } else {
            if(h == 0) f[1]++;
            else c[1]++;  
        }
    } else if(mi == 3) { // 西
        if(mp[x][y-1] == '*') {
            if(h == 0) f[0] = 0;
            else c[0] = 0;
        } else {
            if(h == 0) f[2]--;
            else c[2]--;  
        }
    }
}
bool pd() { 
	if (f[1] == c[1] && f[2] == c[2]) 
        return 0;
	else 
        return 1;
}
int main() {
    for(int i = 0; i <= 11; i++) {
        mp[i][0] = '*';
        mp[i][11] = '*';
    }
    for(int i = 1; i <= 11; i++) {
        mp[0][i] = '*';
        mp[11][i] = '*';
    }// 地图四周都围上障碍,方便判断
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'F') f[1] = i, f[2] = j; //记录坐标
            if(mp[i][j] == 'C') c[1] = i, c[2] = j;
        }
    }
    while(pd()) {
        t = f[1] + f[2]*10 + c[1]*100 + c[2]*1000 + f[0]*10000 + c[0]*40000;
        if(xh[t]) {
            cout << 0 << endl;
            exit(0); // 进入了死循环
        }
        xh[t] = 1; // 标记已经来过
        move(f[1], f[2], f[0], 0);
        move(c[1], c[2], c[0], 1);
        ans++;
    }
    cout << ans << endl;
    return 0;
}