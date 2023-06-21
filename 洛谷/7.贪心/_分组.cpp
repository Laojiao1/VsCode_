// 一道绿题！！！ https://www.luogu.com.cn/problem/P4447
// 有一个比较重要的点，就是如果多个栈满足条件，
// 则应该选择建立顺序偏后的栈，因为元素数量会更少一些。
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
stack<int> st[N];
int a[N];
int n;
int minn = 1 << 30;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int num = 0;
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = num; j > 0; j--) { 
            if(st[j].top() + 1 == a[i]) { // 如果当前栈中元素与当前元素相邻的话
                st[j].push(a[i]); // 把当前元素放进此栈;
                flag = 1; //标记点, 如果flag = 1的话就不用造新栈了
                break; // 执行完入栈操作后直接break
            } else {
                flag = 0; // 如果为0，就需要造一个新栈
            }
        }
        if(flag == 0) { // 如果flag = 0的话
            num++; // 开一个新的栈
            st[num].push(a[i]); // 把不相邻的元素放到新的栈里
        }
    }
    for(int i = 1; i <= num; i++) {
        int size_ = st[i].size();
        minn = min(minn, size_);
    }
    cout << minn << endl;
    return 0;
}