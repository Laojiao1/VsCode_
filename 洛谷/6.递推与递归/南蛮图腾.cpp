// 分治，递推 (挺有意思的)
// https://www.luogu.com.cn/problem/P1498
#include <bits/stdc++.h>
using namespace std;
int n;
char a[3000][3000];
int h = 2, w = 4; // 初始图形宽4，高2
int main() {
    cin >> n;
    memset(a, ' ', sizeof(a));
    // 先打个基础图形的表
    a[1][1]=a[1][4]=' ';
	a[1][2]=a[2][1]='/';
	a[1][3]=a[2][4]='\\';// 注意这里要两个，第一个代表转义字符
	a[2][2]=a[2][3]='_';
    for(int i = 1; i < n; i++) { // 第n个图，需要进行n-1次转换
        //向下和向右
        for(int j = 1; j <= h; j++) {
            for(int k = 1; k <= w; k++) {
                a[j+h][k] = a[j+h][k+w] = a[j][k];
                a[j][k] = ' '; //把上面的清除
            }
        }
        //向上
        for(int j = 1; j <= h; j++){
			for(int k = 1; k <= w; k++){
				a[j][k + w/2] = a[j+h][k];
			}
		}
        // 重置数据
        w *= 2; 
        h *=2;
    }
    // 输出
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}