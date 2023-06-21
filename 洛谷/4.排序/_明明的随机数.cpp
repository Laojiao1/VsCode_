// P1059
// 用STL-set(集合) 去除数组中的重复元素
// set 默认从小到大排序
// begin() 　　     返回set容器的第一个元素的 地址
// end() 　　　　   返回set容器的最后一个元素 "地址" 
// clear() 　　     删除set容器中的所有的元素
// empty() 　　　   判断set容器是否为空
// max_size() 　    返回set容器可能包含的元素最大个数
// size() 　　　　   返回当前set容器中的元素个数
// erase(it)        删除迭代器指针it处元素
// insert(a)        插入某个元素
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a[1001];
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    cout << s.size() << endl;
    // 两种遍历方法都可以
    while(!s.empty()) {
        cout << *s.begin() << " "; 
        s.erase(s.begin());
    }
    // for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    return 0;
}

// 思路二 —— 桶排序
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n, x;
//     cin >> n;
//     int sum = 0, bus[1001] = {0};
//     for(int i = 1; i <= n; i++) {
//         cin >> x;
//         if(bus[x]) continue; // 如果出现过一次了，就跳过不管
//         bus[x]++;
//         sum++;
//     }
//     cout << sum << endl;
//     for(int i = 1; i <= 1000; i++) {
//         if(bus[i]) cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }