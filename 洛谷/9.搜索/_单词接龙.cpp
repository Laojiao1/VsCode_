// 字符串搜索(奇奇怪怪的题型)
// 一个单词最多用两次
// 单词可以不全用完
// 不可以包含：一旦包含了和不用岂不是一样
// 按照贪心原则，重叠部分应该越少越好
// https://www.luogu.com.cn/problem/P1019
#include <bits/stdc++.h>
using namespace std;
string str[20];
int use[20], length = 0, n;
// 返回最小重叠长度
int canlink(string str1, string str2) {
    int l = min(str1.length(), str2.length());
    for(int i = 1; i < l; i++) { // 遍历范围到l-1，避免包含
        int flag = 1;
        for(int j = 0; j < i; j++) {
            if(str1[str1.length()- i + j] != str2[j]) {
                // 从str1单词尾部一个一个与str2单词头部进行遍历比较。
                // 这个写法可以注意一下
                flag = 0;
            }
        }
        if(flag) return i;
    }
    return 0; // 无重叠部分返回0
}
// 搜索
void dfs(string strnow, int lenghtnow) {
    length = max(lenghtnow, length);
    for(int i = 0; i < n; i++) {
        if(use[i] >= 2) continue; // 使用次数不能大于2
        int c = canlink(strnow, str[i]);
        if(c > 0) {
            use[i]++;
            dfs(str[i], lenghtnow + str[i].length() - c);
            use[i]--; // 回溯
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        use[i] = 0;
        cin >> str[i];
    }
    dfs(' ' + str[n], 1);
    cout << length << endl;
    return 0;
}