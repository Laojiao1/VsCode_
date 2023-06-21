// 离散化，值得学习
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
stack<int> s;
int table[N], block[317];
void push(int n) {
    s.push(n);
    table[n]++;
    block[n / 317] ++; // 离散化，大数转换为小数，缩短查找时间
}
int pop() {
    int n = s.top();
    s.pop();
    block[n / 317]--;
    table[n]--;
    return n;
}
int peekMedian() {
    int len = (s.size() + 1) / 2; // 无论奇偶
    int i = 0, j = 0;
    // 先粗略的寻找范围
    while(j + block[i] < len) {
        j += block[i++];
    }
    int k = i * 317;
    // 然后细找（因为在离散化的时候有可能一个下标被不同数标记了两次，如果两个数较为接近的话）
    while(j + table[k] < len) {
        j += table[k++];
    }
    return k;
}
int main() {
    int n;
    cin >> n;
    char cmd[30];
    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd[1] == 'o') {
            if(s.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << pop() << endl;
            }
        } else if(cmd[1] == 'u') {
            int num;
            cin >> num;
            push(num);
        } else {
            if(s.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << peekMedian() << endl;
            }
        }
    }
    return 0;
}