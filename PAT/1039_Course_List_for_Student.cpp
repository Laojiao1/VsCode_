#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    map<string, vector<int>> data;
    string name;
    for(int i = 0; i < k; i++) {
        int j, L;
        scanf("%d %d", &j, &L);
        for(int k = 0; k < L; k++) {
            cin >> name;
            data[name].push_back(j);
        }
    }
    // vector<int> *v;
    // for(int i = 0; i < n; i++) {
    //     cin >> name;
    //     v = &data[name];
    //     sort(v->begin(), v->end());
    //     cout << name.c_str() << " " << v->size();
    //     for(auto it = v->begin(); it != v->cend(); it++) {
    //         cout << " " << *it;
    //     }
    //     cout << endl;
    // }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> name;
        v = data[name];
        sort(v.begin(), v.end());
        cout << name << " " << v.size();
        for(auto it : v) {
            cout << " " << it;
        }
        cout << endl;
    }
    return 0;
}

