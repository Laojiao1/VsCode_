// 贪心 排序 + 双指针
// https://www.luogu.com.cn/problem/P4995
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1001;
int n;
ll ans = 0;
int a[N];
int main() {
    cin >> n;
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int l = 0, r = n;
    while(l < r) {
        ans += pow((a[r] - a[l]), 2);
        l++;
        ans += pow((a[r] - a[l]), 2);
        r--;
    }
    cout << ans << endl;
    return 0;
}
// 写法二：
// STL —— deque容器可以实现双指针功能
// #include <bits/stdc++.h>
// using namespace std;
// int ans = 0;
// deque<int> q;
// int a[1001];
// int n;
// int main() {
//     cin >> n;
//     a[0] = 0;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     sort(a, a+1+n);
//     for(int i = 0; i <= n; i++) {
//         q.push_back(a[i]);
//     }
//     // for(int i = 0; i <= n; i++) {
//     //     cout << q.front() << " ";
//     //     q.pop_front();
//     // }
//     while(q.size() >= 2) {
//         ans += pow((q.back() - q.front()), 2);
//         q.pop_front();
//         ans += pow((q.back() - q.front()), 2);
//         q.pop_back();
//     }
//     cout << ans << endl;
//     return 0;
// }