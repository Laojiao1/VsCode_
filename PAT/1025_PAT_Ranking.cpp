// 排序
#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Node {
    long long code;
    int grade;
    int local;
    int localRank;
    int finalRank;
};
bool cmp(Node s1, Node s2) {
    if(s1.grade != s2.grade) {
        return s1.grade > s2.grade;
    } else {
        return s1.code < s2.code;
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    vector<Node> res;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cin >> k;
        vector<Node> v(k);
        for(int j = 0; j < k; j++) {
            scanf("%lld %d", &v[j].code, &v[j].grade);
            v[j].local = i;
        } 
        sort(v.begin(), v.end(), cmp);
        // 计算考生在考场内的排名，并将其加入f向量中
        v[0].localRank = 1;
        res.push_back(v[0]);
        for(int t = 1; t < k; t++) {
            if(v[t].grade == v[t-1].grade) {
                v[t].localRank = v[t-1].localRank;
            } else {
                v[t].localRank = t+1;
            }
            res.push_back(v[t]);
        }
    }
    sort(res.begin(), res.end(), cmp);
    res[0].finalRank = 1;
    const long len = res.size();
    for(int i = 1; i < len; i++) {
        if(res[i].grade == res[i-1].grade) {
            res[i].finalRank = res[i-1].finalRank;
        } else {
            res[i].finalRank = i+1;
        }
    }
     printf("%ld\n", res.size());
    for(auto it = res.cbegin(); it != res.cend(); it++) {
        printf("%013lld %d %d %d\n", it->code, it->finalRank, it->local, it->localRank);
    }
    return 0;
}
