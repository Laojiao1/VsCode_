// 埃氏筛法
// 要得到自然数n以内的全部素数，必须把不大于根号n的所有素数的倍数剔除，剩下的就是素数。
// 写法一：
#include <stdio.h>
#include <math.h>
bool is_prime[1000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        is_prime[i] = true;                    //初始化所有的数为素数
    }
    for(int i = 2; i <= sqrt(n); i++){         //从第一个素数2开始筛选
        if(is_prime[i]) {                       //如果是素数
            for(int j = i*i; j <= n; j += i){  //则剔除掉它的倍数
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++){
         if(is_prime[i]){
             printf("%d\n", i);
         }
    }
    return 0;
}
// 写法二：
// #include <bits/stdc++.h>
// using namespace std;
// int f[1001];
// int main() {
//     int n;
//     cin >> n;
//     for(int i = 2; i <= n; i++) {
//         for(int j = i*2; j <= n; j += i) {
//             if(f[j] == 0) {
//                 f[j] = 1;
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++) {
//         if(f[i] == 0) cout << i << " ";
//     }
//     return 0;
// }
