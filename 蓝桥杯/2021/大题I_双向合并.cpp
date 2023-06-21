// 想Ac的话可以用线段树
// 这里只用了贪心+模拟+排序的方法
#include <bits/stdc++.h>
using namespace std;
struct Oper {
    int op;
    int pos;
};
bool cmp(int x, int y) {
    return x > y;
}
int n, m, a[100052];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<Oper> OpList;
    for(int i = 0; i < m; i++) {
        Oper temp;
        cin >> temp.op >> temp.pos;
        OpList.push_back(temp);
    }
    // 去重（缩短时间）
    vector<Oper> newList;
    Oper curop = OpList[0];
    for(unsigned int i = 0; i < OpList.size(); i++) {
        if(curop.op != OpList[i].op) {
            newList.push_back(curop);
            curop = OpList[i];
            continue;
        }
        if(OpList[i].op == 0 && OpList[i].pos > curop.pos) {
            curop = OpList[i];
        }
        if(OpList[i].op == 1 && OpList[i].pos < curop.pos) {
            curop = OpList[i];
        }
    }
    for(int i = 0; i < newList.size(); i++) {
        if(newList[i].op == 0) {
            sort(a, a + newList[i].pos, cmp);
        } else {
            sort(a + newList[i].pos - 1, a + n);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}