//水题
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a[5005];
    int flag = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == a[a[a[i]]]) {
            flag = 1; 
            break;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}