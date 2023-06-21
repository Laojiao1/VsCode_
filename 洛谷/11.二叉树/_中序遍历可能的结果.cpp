// 已知先序遍历和后序遍历，求中序遍历可能出现的结果种类
// https://www.luogu.com.cn/problem/P1229
// 首先要明白：只有一个儿子的结点才会在知道前序和后序的情况下有不同的
// 中序遍历, 所以将题目转化为找只有一个儿子的结点个数
// 规律：若前序遍历中出现AB，后序遍历在出现BA，则只有一个儿子
#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int ans = 0;
int main() {
    cin >> str1;
    cin >> str2;
    for(int i = 0; i < str1.length(); i++) {
        for(int j = 1; j < str2.length(); j++) {
            if(str1[i] == str2[j] && str1[i+1] == str2[j-1]) {
                ans++;
            }
        }
    }
    ans = 1 << ans;
    cout << ans << endl;
    return 0;
}