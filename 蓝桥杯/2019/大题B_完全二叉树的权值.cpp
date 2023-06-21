// 利用完全二叉树的性质快速求解
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int min_depth = 0;
    int max_sum = 0;
    int sum = 0;
    int depth = 1;
    int a[100005];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        if(i == pow(2, depth) - 1) {
            if(max_sum < sum) {
                max_sum = sum;
                min_depth = depth;
            }
            depth++;
            sum = 0;
        }

    }
    cout << min_depth << endl;
    return 0; 
}
