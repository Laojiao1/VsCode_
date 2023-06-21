// 按照字典序输出自然数 1 到 n 所有不重复的排列，
// 即 n 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。
//     3
    // 1    2    3
    // 1    3    2
    // 2    1    3
    // 2    3    1
    // 3    1    2
    // 3    2    1
// 直接上STL —— next_purmotation()
// https://www.luogu.com.cn/problem/P1706
#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    cout << "    ";
    do {
        for(int i = 1; i <= n; i++) {
            cout << a[i] << "    ";
        }
        cout << endl;
        cout << "    ";
    } while(next_permutation(a+1, a+1+n));
    return 0;
}

// 正常思路：回溯+剪枝
#include<bits/stdc++.h>
using namespace std;
int n,pd[100],used[100];//pd是判断是否用过这个数
void print()//输出函数
{
    int i;
    for(i = 1; i <= n; i++)
    printf("%5d", used[i]);//保留五位常宽
    cout << endl;
}
void dfs(int k)//深搜函数，当前是第k格
{
    int i;
    if(k > n) // 当溢出的时候就输出
    {
        print();//输出当前解
    }
    for(i = 1; i <= n; i++)//1-n循环填数
    {
        if(!pd[i])//如果当前数没有用过
        {
            pd[i] = 1;//标记一下
            used[k] = i;//把这个数填入数组
            dfs(k+1);//填下一个
            pd[i] = 0;//回溯
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
