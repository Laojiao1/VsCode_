#include <bits/stdc++.h>
using namespace std;
struct Node {
    string name;
    string id;
    int tag;
    int time;
    int order;
} person[1005];
struct Node1 {
    string name, id;
};
vector<Node1> v;
map<string, int> vis;
map<string, bool> flag;
bool check(string id) { // 检查合法性
    int len = id.size();
    if(len != 18) return false;
    for(int i = 0; i < len; i++) {
        if(id[i] < '0' || id[i] > '9') return false;
    }
    return true;
}
bool cmp(Node s1, Node s2) {
    if(s1.time != s2.time) return s1.time < s2.time;
    return s1.order < s2.order;
}
int main() {
    freopen("in.in", "r", stdin);
    int d, p;
    cin >> d >> p;
    vis.clear();
    v.clear();
    flag.clear();
    for(int i = 1; i <= d; i++) {
        int t, s;
        string name, id;
        int tag, h, sec;
        int cnt = 0;
        char c;
        cin >> t >> s;
        for(int j = 1; j <= t; j++) {
            cin >> name >> id >> tag >> h >> c >> sec;
            if(!check(id)) continue;
            cnt++;
            person[cnt].name = name;
            person[cnt].id = id;
            person[cnt].tag = tag;
            person[cnt].time = c * 60 + sec;
            person[cnt].order = cnt;
            if(tag == 1) {
                if(!flag[id]) {
                    v.push_back({name, id});
                    flag[id] = 1;
                }
            }
        }
        sort(person+1, person+cnt+1, cmp);
        int tot = 0;
        for(int k = 1; k <= cnt; k++) {
            id = person[k].id;
            if(!vis[id]) {
                cout << person[k].name << " " << person[k].id << endl;
                vis[id] = i; // 第i天领了口罩
                tot++;
            } else {
                int day = vis[id];
                if(i - day <= p) continue;
                cout << person[k].name << " " << person[k].id << endl;
                vis[id] = i;
                tot++;
            }
            if(tot == s) break;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].name << " " << v[i].id << endl;
    }
    return 0;
}
