// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     vector<long long int> primeNum, primeVal;
//     long long int x = 2021041820210418;
//     for(long long int i = 2 ; i * i <= x; i++) {
//         if(x % i == 0) {
//             int num = 0;
//             while(x % i == 0) {
//                 x /= i;
//                 num++;
//             }
//             primeNum.push_back(num);
//             primeVal.push_back(i);
//         }
//     }
//     if(x > 1) {
//         primeNum.push_back(1);
//         primeVal.push_back(x);
//     }
//     for(unsigned i = 0; i < primeNum.size(); i++) {
//         cout << primeVal[i] << " " << primeNum[i] << endl;
//     }
//     // 2 1      
//     // 3 3      
//     // 17 1     
//     // 131 1    
//     // 2857 1   
//     // 5882353 1
//     // 由于2021041820210418能分解为2^1 + 3^3 + 17^1 + 131^1 + 2857^1 + 5882353^1;
//     // 对于2, 3, 17, 2857, 5882353说，他们各自可以拆分成3个不同的质因数之积，所以不同的组合数量为3^5
//     // 对于3个3来说，可以用枚举法得出一共有10种方案
//     // 因此总共有3^5*10种组合方法
//     cout << 3*3*3*3*3*10 << endl;
//     // 答案为2430
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num = 2021041820210418, res = 0;
ll a[3000], cnt = 0;
int main() {
    for(int i = 1; i <= sqrt(num); i++) {
        if(num % i == 0) {
            a[++cnt] = i;
            if(i * i != num) a[++cnt] = num / i;
        }
    }
    // for(int i = 1; i <= cnt; i++) {
    //     cout << a[i] << " ";
    // }
    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= cnt; j++) {
            for(int k = 1; k <= cnt; k++) {
                if(a[i] * a[j] * a[k] == num) {
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}