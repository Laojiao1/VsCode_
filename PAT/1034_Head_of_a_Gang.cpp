#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2001
int parent[MAX_N], r[MAX_N], k[MAX_N], w[MAX_N];
// 集合数组，子树大小，time总数
int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
int population = 0;
map<string, int> indexs;
string names[MAX_N*2]; // 存储名字信息
void Union(int p, int q, int t) { // 合并成一个集合
    int rootP = find(p), rootQ = find(q); // 查找他们的父亲
    if(rootP == rootQ) {
        k[rootP] += t; // 收录进集合，数组内存储总time
        return;
    }
    // 总是将小树合并到大树上，如果两棵树高度一样，则任意合并，合并后树的高度加1，合并树的同时合并计数
    if(r[rootP] < r[rootQ]) {
        parent[rootP] = rootQ;
        k[rootQ] += k[rootP] + t;
    } else if(r[rootP] > r[rootQ]) {
        parent[rootQ] = rootP;
        k[rootP] += k[rootQ] + t;
    } else {
        parent[rootQ] = rootP;
        k[rootP] += k[rootQ] + t;
        r[rootP]++;
    }
}
int getIndex(string s) { // 获得下标
    if(indexs.find(s) == indexs.cend()) {
        // 如果没找到
        indexs[s] = population;
        names[population] = s;
        return population++;
    }
    return indexs[s];
}
// 按照名字字典序进行排序
bool cmp(int h1, int h2) {
    return names[h1] < names[h2];
}
vector<int> gangs[MAX_N];
int head[MAX_N], cnt = 0;
int main() {
    freopen("in.in", "r", stdin);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < MAX_N; i++) {
        parent[i] = i;
        w[i] = 0;
        r[i] = 0;
        k[i] = 0;
    }
    string s1, s2;
    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2;
        int t;
        cin >> t;
        int u = getIndex(s1);
        int v = getIndex(s2);
        Union(u, v, t);
        w[u] += t;
        w[v] += t;
    }
    // 将每个人加入到自己的组中
    for(int i = 0; i < population; i++) {
        gangs[find(i)].push_back(i);
    }
    for(int i = 0; i < population; i++) {
        int size, h;
        // 过滤k值和人数不符合的组
        if(k[i] <= K || (size = (int)gangs[i].size()) <= 2) {
            continue;
        }
        // 遍历组内成员获得头目(通话时间最长的)
        h = i;
        for(int p : gangs[i]) {
            if(w[p] > w[h]) {
                h = p;
            }
        }
        head[cnt++] = h;
    }
    sort(head, head+cnt, cmp); // 按照字典序进行排序
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        int p = head[i];
        cout << names[head[i]].c_str() << " " << (int)gangs[parent[p]].size() << endl;
    }
    return 0;
}