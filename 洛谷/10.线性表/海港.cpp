// 细节模拟题
// https://www.luogu.com.cn/problem/P2058
#include <bits/stdc++.h>
using namespace std;
struct node {
    int time;
    int country;
};
int n, ans;
int bus_nation[500005];// 利用桶排序思想记录来过的国家数量
queue<node> q;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t, num;
        cin >> t >> num;
        for(int i = 1; i <= num; i++) {
            node Person;
            int nation;
            cin >> nation; // 读入每个人所在的国家
            Person.time = t; // 记录到站时间
            Person.country = nation; // 记录国家
            q.push(Person);  // 存入结构体
            bus_nation[nation]++; // 记录已经来过的国家
            if(bus_nation[nation] == 1) { // 如果是第一次来, ans++
                ans++;
            }
        }
        // 开始进行出队环节
        while(!q.empty()) {
            node a;
            a = q.front(); // 取出队列头部元素
            if(a.time + 86400 <= t) { // 如果当前t在时间范围外
                bus_nation[a.country]--; // 队列头部所有到达的国家数减1 
                if(bus_nation[a.country] == 0) {
                    ans--; // 如果国家没人了就ans--
                }
                q.pop();// 抛出队列
                continue; // 因为是单调递增的，所以有可能还会有，继续去找
                // continue: 跳出if语句，直接继续判断while条件继续执行下一次循环
            }
            break; // 如果在时间范围内直接退出 
        }
        cout << ans << endl;
    }
    return 0;
}
