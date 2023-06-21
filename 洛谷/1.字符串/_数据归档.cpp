//字符串可以直接比较大小

//INPUT:
// 9
// 78941BCA78999E67A8FE 170
// A879F89E700768AF898B 180
// 78941BCA78999E67A8FE 179
// A879F89E700768AF898B 200
// FEABCD78797141984748 100
// A879F89E700768AF898B 201
// A879F89E700768AF898B 200
// 78941BCA78999E67A8FE 999
// A879F89E700768AF898B 200

//OUTPUT:
// FEABCD78797141984748 100
// A879F89E700768AF898B 180
// A879F89E700768AF898B 200
// A879F89E700768AF898B 201
// 78941BCA78999E67A8FE 170
// 78941BCA78999E67A8FE 179
// 78941BCA78999E67A8FE 999
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
pair<string, int> p[maxn];

bool cmp(pair<string, int> p1, pair<string, int> p2) {
    if(p1.first != p2.first) {
        return p1.first > p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second; 
    }
    sort(p+1, p+1+n, cmp);
    for(int i = 1; i < n; i++) {
        if(p[i].first == p[i+1].first && p[i].second == p[i+1].second) 
            continue;
        cout << p[i].first << " " << p[i].second << endl;
    }
    cout << p[n].first << " " << p[n].second << endl;
    return 0;
}
