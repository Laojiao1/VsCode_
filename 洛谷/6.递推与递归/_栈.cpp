// P1044 https://www.luogu.com.cn/problem/P1044
// 解法一：记忆化优先搜索
#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
long long f[20][20]; // 记录方案数
long long dfs(int x, int y) { // x是操作队列里元素的个数，y是栈里的个数
    if(f[x][y] != 0) return f[x][y]; //走过的方案直接调用
    if(x == 0) return 1; // 如果操作队列里没有数了，那么就只有一种方案了
    if(y > 0) f[x][y] += dfs(x, y-1);//当栈里元素个数大于0的时候，才可以进行操作
    f[x][y] += dfs(x-1, y+1); //操作队列里的元素个数减一，栈里元素个数加1
    return f[x][y]; //返回方案值
}
int main() {
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}

//方法二 —— 卡特兰数
// 建立数组f。f[i]表示i个数的全部可能性。
// f[0] = 1, f[1] = 1; //当然只有一个
// 设 x 为当前出栈序列的最后一个，则x有n种取值
// 由于x是最后一个出栈的，所以可以将已经出栈的数分成两部分
// 比x小
// 比x大
// 比x小的数有x-1个，所以这些数的全部出栈可能为f[x-1]
// 比x大的数有n-x个，所以这些数的全部出栈可能为f[n-x]
// 这两部分互相影响，所以一个x的取值能够得到的所有可能性为f[x-1] * f[n-x]
// 另外，由于x有n个取值，所以
// ans = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-1]*f[0];
// 这，就是传说中的卡特兰数

// #include <bits/stdc++.h>
// using namespace std;
// int n, f[30];
// int main()
// {
//     //递推实现卡特兰数 
//     scanf("%d", &n);
//     f[0] = 1, f[1] = 1;
//     for(int i = 2; i <= n; i++)              
//         for(int j = 0; j < i; j++) 
//             f[i] += f[j] * f[i-j-1];     //递推公式 
//     printf("%d", f[n]);
//     return 0;
// }