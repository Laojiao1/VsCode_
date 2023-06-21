// 给出一个正整数n，按从外向内的螺旋顺序打印1到n^2的所有数值
#include <bits/stdc++.h>
using namespace std;
int n, mp[101][101];
int main() {
    cin >> n;
    int startx = 0, starty = 0;
    int loop = n / 2;
    int mid = n / 2;
    int count = 1;
    int countset = 1;
    int i, j;
    while(loop--) {
        i = startx;
        j = starty;
        for(j = starty; j < n + starty - countset; j++) {
            mp[startx][j] = count++;
        }
        for(i = startx; i < n + startx - countset; i++) {
            mp[i][j] = count++;
        }
        for( ; j > starty; j--) {
            mp[i][j] = count++;
        }
        for( ; i > startx; i--) {
            mp[i][j] = count++;
        }
        startx ++;
        starty ++;
        countset += 2;
    }
    if(n % 2 == 1) mp[mid][mid] = count;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}