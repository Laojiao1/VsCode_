// 非常经典的例题 https://www.luogu.com.cn/problem/P1219
// 搜索 + 回溯
// 补充知识：对于一条从右上到左下的对角线，其上的棋子坐标应满足x+y为一定值
// 对于一条从左上到右下的对角线，其上的棋子坐标应满足x-y为一定值，为了避免变成负数，再加一个n
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], b[N], c[N], d[N];
// 行，列，左下到右上，左上到右下
int ans = 0;
int n;
void print() {
    if(ans <= 2) {
        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    ans++;
}
void search(int k) { // 第k行
    if(k > n) { // 搜索出口
        print();
        return;
    } else {
        // 开始遍历可能的位置
        for(int i = 1; i <= n; i++) {
            if(!b[i] && !c[k+i] && !d[k-i+n]) { // 判断有没有皇后占领
                a[k] = i; // 标记第k行是第i个 
                b[i] = 1; // 把当前纵列占领
                c[k+i] = 1;
                d[k-i+n] = 1;
                search(k+1);
                // 回溯
                b[i] = 0;
                c[k+i] = 0;
                d[k-i+n] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    search(1);
    cout << ans << endl;
    return 0;
}