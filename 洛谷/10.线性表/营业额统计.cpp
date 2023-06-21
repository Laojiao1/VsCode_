// STL - set(集合) 自动排序 + 不能插入重复元素
#include <bits/stdc++.h>
using namespace std;
using itSet = set<int>::iterator;
const int inf = 1 << 30;
int n, ans;
set<int> s;
int main() {
    cin >> n;
    // 小tip：插入无限大无限小，防止迭代器访问到奇奇怪怪的内存
    s.insert(inf);
    s.insert(-inf); 
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(s.size() == 2) {
            ans += a; 
            s.insert(a);
        } else {
            itSet pos = s.lower_bound(a);
            if(*pos != a) {
                itSet nowPos = pos;
                pos--;
                ans += min(abs(*pos - a), abs(*nowPos - a));
                s.insert(a);
            }
        }
    }
    cout << ans << endl;
    return 0;
}