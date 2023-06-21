#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
char s[N];
int ch[N][26], cnt[N], idx;
// ch[p][j] 存储从结点p沿着j这条边走到的子结点边为26个小写字母(a~z)对应映射值0~25，每个节点最多可以有26个分叉
// cnt[p]存储以结点p结尾的单词的插入次数
// idx用来给节点编号
void insert(char *s) {
    int p = 0;
    for(int i = 0; s[i]; i++) {
        int j = s[i] - 'a';
        if(!ch[p][j]) ch[p][j] = ++idx;
        p = ch[p][j];
    }
    cnt[p]++;
}
int query(char *s) {
    int p = 0;
    for(int i = 0; s[i]; i++) {
        int j = s[i] - 'a';
        if(!ch[p][j]) return 0;
        p = ch[p][j];
    }
    return cnt[p]; // 返回插入次数
}