// 考察链表
// 经典！
// https://www.luogu.com.cn/problem/P1160
#include <bits/stdc++.h>
using namespace std;
using Iter = list<int>::iterator; // 懒人必备
const int maxn = 1e5 + 10;
Iter pos[maxn]; // 元素i的迭代器
list<int> queList;
bool erased[maxn]; // 标记该元素是否已经删除过
int n;
void buildQueue() {
    queList.push_front(1);
    pos[1] = queList.begin();
    for(int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if(b == 0) {
            pos[i] = queList.insert(pos[a], i); 
            // 把第i个同学插入到a同学的左边(insert默认插到*it的左边)
        } else {
            // auto: 自动存储变量的关键字, 可以自动判断变量的类型
            auto nextIter = next(pos[a], 1);
            // next(*it, num); 表示把迭代器*it向右挪动num个位置
            pos[i] = queList.insert(nextIter, i);
            // 把第i个同学插入到a同学的右边
        }
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if(!erased[x]) { // 如果没被删除
            queList.erase(pos[x]);// 删除元素
        }
        erased[x] = 1; // 标记已删除
    }
}
int main() {
    cin >> n;
    buildQueue();
    for(int x : queList) { // 对容器进行遍历
        cout << x << " ";
    }
    cout << endl;
    return 0;
}