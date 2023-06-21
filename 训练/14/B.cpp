#include <bits/stdc++.h>
using namespace std;
struct set_ {
    int l, r, len;
    int temp;
} a[1001];
bool cmp(set_ s1, set_ s2) {
    return s1.len < s2.len;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool vis[1001] = {0};
        for(int i = 1; i <= n; i++) {
            cin >> a[i].l >> a[i].r;
            a[i].len = a[i].r - a[i].l;
        }
        sort(a+1, a+1+n, cmp);//对区间进行排序
        for(int i = 1; i <= n; i++) {
            if(a[i].l == a[i].r) {
                a[i].temp = a[i].l;
                vis[a[i].temp] = 1; //区间相等直接赋值标记
            } else {
                for(int j = a[i].l; j <= a[i].r; j++) { //不相等的话就枚举
                    if(!vis[j]) {
                        a[i].temp = j;
                        vis[j] = 1;//标记已经访问
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << a[i].l << " " << a[i].r << " " << a[i].temp << endl;
        }
        cout << endl;
    }
    return 0;
}