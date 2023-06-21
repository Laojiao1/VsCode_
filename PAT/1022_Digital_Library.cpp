// map的应用
#include <bits/stdc++.h>
using namespace std;
map<string, vector<int>> m[6];
int main() {
    freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    int id;
    string str;
    while(n-- > 0) {
        scanf("%d\n", &id);
        for(int i = 1; i < 6; i++) {
            if(i == 3) {
                while(cin >> str) {
                    m[i][str].push_back(id);
                    if(getchar() == '\n') {
                        break;
                    }
                }
            } else {
                getline(cin, str);
                m[i][str].push_back(id);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int id;
        string key;
        scanf("%d: ", &id);
        getline(cin, key);
        map<string, vector<int> > &mm = m[id];
        cout << id << ": " << key << endl;
        if(mm.find(key) != mm.end()) {
            vector<int> res = mm[key];
            sort(res.begin(), res.end());
            for(auto it = res.begin(); it != res.end(); it++) {
                printf("%07d\n", *it);
            }
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}
