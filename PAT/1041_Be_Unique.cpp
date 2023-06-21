// 求数列中第一个唯一出现的数并输出，否则输出None
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int cnt[N], bets[N];
int main() {
   // freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bets[i] = num;
        cnt[num]++;        
    }
    bool flag = 1;
    for(int i = 0; i < n; i++) {
        if(cnt[bets[i]] == 1) {
            cout << bets[i] << endl;
            flag = false;
            break;
        }
    }
    if(flag == 1) {
        cout << "None" << endl;
    }
    return 0;
}