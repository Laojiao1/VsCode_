// https://www.luogu.com.cn/problem/P4387
#include <bits/stdc++.h>
using namespace std;
stack<int> q;
int n;
int main() {
    cin >> n;
    while(n--) {
        int num, sum = 1;
        cin >> num;
        int a[100001], b[100001];
        for(int i = 1; i <= num; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= num; i++) {
            cin >> b[i];
        }
        for(int i = 1; i <= num; i++) {
            q.push(a[i]);
            while((q.top()) == b[sum]) { // 如果当前栈头与b[]当前数相对应
                q.pop();
                sum++;
                if(q.empty()) break; // 注意这里一定要有break，防止死循环
            }
        }
        if(q.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        while(!q.empty()) q.pop(); // 别忘了清空栈
    }
    return 0;
}