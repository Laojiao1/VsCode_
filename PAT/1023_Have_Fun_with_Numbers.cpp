// 单高精度乘法
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
string nums;
int a[N], b[N], c[N];
int main() {
    //freopen("in.in", "r", stdin);
    cin >> nums;
    int len = 0;
    for(int i = 0; i < nums.size(); i++) {
        a[i] = nums[i] - '0';
        len++;
    }
    // for(int i = 0; i < len; i++) {
    //     cout << a[i] << " ";
    // }
    int temp = 0;
    for(int i = len-1; i >= 0; i--) {
        int n = a[i] * 2 + temp;
        b[i] = n % 10;
        temp = n / 10; // 进位
    }
    bool flag = 1;
    if(temp > 0) {
        flag = 0;
    } else {
        for(int i = 0; i < len; i++) {
            c[a[i]]++;
        }
        for(int i = 0; i < len; i++) {
            c[b[i]]--;
        }
        for(int i = 0; i < 10; i++) {
            if(c[i] != 0) {
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    if(temp > 0) cout << temp;
    for(int i = 0; i < len; i++) {
        cout << b[i];
    }
    return 0;
}