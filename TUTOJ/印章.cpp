// #include <bits/stdc++.h>
// using namespace std;
// int mp[101][101];
// int main() {
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             cin >> mp[i][j];
//         }
//     }
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(mp[i][j] == 1 && i != j) {
//                 mp[i][i] = mp[j][j] = mp[j][i] = 1;
//             } else if(mp[i][j] == 1 && i == j && i != n){
//                 if(i == 1) {
//                     mp[i][n] = mp[n][i] = mp[n][n] = 1;
//                 } else {
//                     if(n % 2 == 0) {
//                         int m = fabs(i-n/2);
//                         if(i > n/2) mp[i-m][j-m] = mp[i][j-m] = mp[i-m][j] = 1;
//                         else mp[i+m][j+m] = mp[i][j+m] = mp[i+m][j] = 1;
//                     } else {
//                         if(i != n/2+1) {
//                             int t = fabs(i - n/2);
//                             if(i > n/2+1) mp[i-t][j-t] = mp[i][j-t] = mp[i-t][j] = 1;
//                             else mp[i+t][j+t] = mp[i][j+t] = mp[i+t][j] = 1;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (j == 1) {
//                 cout << mp[i][j];
//             }
//             else {
//                 cout << " " << mp[i][j];
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
int mp[101][101];
void solve(int a[][101]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                continue;
            }
            a[i][j] = a[n + 1 - j][i];
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= 3; i++) {
        solve(mp);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                cout << mp[i][j];
            }
            else {
                cout << " " << mp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}