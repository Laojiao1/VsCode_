// #include <bits/stdc++.h>
// using namespace std;
// void to_arrary(int n,int num[], int length) {
// 	for(int i=1; i <= length; i++){
// 		num[i] = n % 10;
// 		n /= 10;
// 	}
// }
// int main() { 
//     //freopen("in.in", "r", stdin);
//     int t;
//     cin >> t;
//     while(t--) {
//         int num, n;
//         cin >> num >> n;
//         int arr[10001];
//         int cnt1 = 0, cnt2 = 0;
//         to_arrary(n, arr, num);
//         // for(int i = 1; i <= num; i++)
//         //     cout << arr[i] << " ";
//         for(int i = 1; i <= num/2; i++) {
//             if(arr[i] == arr[num-i+1]) {
//                 cnt1++;
//             }
//             else {
//                 cnt2++;
//             }
//         }
//         //cout << cnt1 << " " << cnt2 << endl;
//         if(cnt1 == 0 || cnt2 == 0) {
//             cout << "Yes" << endl;
//         } else {
//             cout << "No" << endl;
//         }
//         memset(arr, 0, sizeof(arr));
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string x = s;
        for(int i = 0; i < n / 2; i++) {
            s[i] = s[n-i-1];
        }
        vector<int> t;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(x[i] == '1' && s[i] == '0') {
                cnt++;
            } else if(s[i] == '1' && x[i] == '0') {
                cnt++;
            } else {
                if(cnt > 0) t.push_back(cnt);
                cnt = 0;
            }
        }
        bool ans = false;
        if(t.size() < 2) ans = true;
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}