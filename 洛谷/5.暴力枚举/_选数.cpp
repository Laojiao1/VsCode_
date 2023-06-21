// P1036 https://www.luogu.com.cn/problem/P1036
// 选数思想
// 本题的重点是如何去重？
// 可以选择不降原则：
// 拿6个里面选3个举例子
// 1 2 3
// 1 2 4
// 1 2 5
// 1 2 6
// 第一轮枚举完毕。
// 第二个数加一
// 1 3 ？
// 这个“？”应该是4，因为是升序排列
// 1 3 4
// 1 3 5
// 1 3 6
// 接着，就是这样
// 1 4 5
// 1 4 6
// 1 5 6
// 第一位是1枚举完毕
// 第一位是2呢?
// 2 3 4
// 2 3 5
// 2 3 6
// 2 4 5
// 2 4 6
// 2 5 6
// 就是这样的，枚举还是蛮清晰的吧
// 以此类推.....
// 3 4 5
// 3 4 6
// 3 5 6
// 4 5 6
// 然后就枚举不了了，结束。
// 所以说，这样就可以避免判重了。
// 代码处理方面：
// 在dfs函数中，我们可以明显看到一个参数startx
// startx代表当前的初始值
// 也就是最小的，符合不降原则的参数，这样一来，就可以去重了.

#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[22];
long long ans = 0;
bool isprime(int x) {
    if(x == 1) {
        return false;
    }
    if(x == 2) {
        return true;
    }
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}
// 关键思想
void dfs(int m, int sum, int startx) {
    // m表示现在选了多少个数
    // sum表示当前的和
    // startx表示升序排列，以免算重复
    if(m == k) { // 如果选的数与k相等了,就判断一下是否是素数然后返回回去
        if(isprime(sum)) ans++;
        // cout << sum << " ";
        return;
    }
    for(int i = startx; i < n; i++) {
        dfs(m+1, sum + a[i], i+1);// 递归
        //步数要加一，和也要加
        //升序起始值要变成i+1,以免算重
    }
    return;//这一个步骤下，所有的都枚举完了
    //直接返回去
}
int main() {   
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}