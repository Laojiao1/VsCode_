#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
int n, m;
vector<int> v[N];
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for(int j = 1; j <= num; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    int cun[N];
    int k = 1;// 记录当前在哪个存档点
    for(int i = 1; i <= m; i++) {
        int choice, j;
        cin >> choice >> j;
        if(choice == 0) {
            k = v[k][j-1];
        } else if(choice == 1) {
            cout << k << endl;
            cun[j] = k;
        } else if(choice == 2) {
            k = cun[j];
        }
    }
    return 0;
}