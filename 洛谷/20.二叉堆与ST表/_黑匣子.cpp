// 二叉堆模板
// 开两个堆，一个大根堆，一个小根堆
// https://www.luogu.com.cn/problem/P1801
#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
priority_queue<int, vector<int>, greater<int> > minn; //小根堆
priority_queue<int, vector<int>, less<int> > maxx; //大根堆
int a[N], u[N];
int main() {
    //freopen("in.in", "r", stdin);
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        while(temp < u[i]) {
            temp++;
            maxx.push(a[temp]); 
            minn.push(maxx.top()); //add操作时，把大根堆的根放入到小根堆
            maxx.pop(); // 删去大根堆的根
        }
        // 当循环退出时，此时小根堆的根就是第i小的元素
        cout << minn.top() << endl;
        maxx.push(minn.top()); // 再把小根堆的根放入到大根堆里
        minn.pop();// 删去小根堆的根
    }
    return 0;
}