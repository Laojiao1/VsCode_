// https://www.luogu.com.cn/problem/P3368
// 树状数组加强板子题
// 1：x y k 含义：将区间 [x,y] 内每个数加上 k；
// 2：2 x 含义：输出第 x 个数的值。
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int input[N], Tree[N];
int n, m;
int lowbit(int x) {
    return x & -x;
}
void add(int x, int k) {
    while(x <= n) {
        Tree[x] += k;
        x += lowbit(x);
    }
}
int search(int x) {
    int ans = 0;
    while(x != 0) {
        ans += Tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> input[i];
    }
    for(int i = 1; i <= m; i++) {
        int choice;
        cin >> choice;
        if(choice == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, z); 
            add(y+1, -z); // 把多加的区间减掉
        }
        if(choice == 2) {
            int x;
            cin >> x;
            cout << input[x] + search(x) << endl;
        }
    }
    return 0;
}
