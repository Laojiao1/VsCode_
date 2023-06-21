// 模拟的水题
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int m, n; // 内存数和单词数
int main() {
    cin >> m >> n;
    int t, cnt = 0;
    while(n--) {
        cin >> t;
        if(find(v.begin(), v.end(), t) == v.end()) { // 如果不在内存中
            v.push_back(t);// 加入内存
            cnt++;
        }
        if(v.size() > m) { // 如果内存满了
            v.erase(v.begin()); // 删除头部元素
        }
    }
    cout << cnt << endl;
    return 0;
}