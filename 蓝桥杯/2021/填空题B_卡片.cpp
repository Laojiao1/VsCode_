#include <bits/stdc++.h>
using namespace std;
const int maxn = 2021;
int res_num[10];
vector<int> Split(int x) { // 十进制拆分
    vector<int> res;
    if(x == 0) {
        res.push_back(0);
        return res;
    } else {
        while(x) {
            res.push_back(x % 10);
            x /= 10;
        }
    }
    return res;
}
bool check(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        res_num[v[i]]--;
        if(res_num[v[i]] < 0) { // 如果有不够用的 就返回false
            return false;
        }
    }
    return true;
}
int main() {
    for(int i = 0; i < 10; i++) {
        res_num[i] = maxn; // 记录每一张卡牌剩余的数量
    }
    int ans = 1;
    while(1) {
        vector<int> temp;
        temp = Split(ans);
        bool flag = check(temp);
        if(flag == 0) {
            break;
        }
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}