// 不能一天一天枚举 否则会超时
// 可以先把前四位数（年份）单独取出来，然后构造回文字符，判断是否合法即可
#include <bits/stdc++.h>
using namespace std;
int dir[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
bool isRun_year(int year) { // 判断闰年
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}
int rever(int i) { // 翻转字符
    vector<int> num;
    int x = i;
    while(x != 0) {
        num.push_back(x % 10);
        x /= 10;
    }
    int ans = num[0];
    for(int i = 1; i < num.size(); i++) {
        ans = ans * 10 + num[i];
    }
    return ans;
}
bool check_1(int x, int y) { // 判断日期是否合法
    // 把月和日单独取出
    int day = y % 10 + (y / 10) % 10 * 10;
    int month = y / 100;
    if(isRun_year(x)) {
        dir[2] = 29;
    } else {
        dir[2] = 28;
    }
    if(month >= 0 && month <= 12 && day >= 1 && dir[month] >= day) {
        return true;
    } else {
        return false;
    }
}  
bool check_2(int x, int y) { // 判断是否为ABABBABA形
    if((x / 1000 == x / 10 % 10) && (x / 100 % 10 == x % 10)) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cin >> n;
    for(int i = n / 10000; i <= 9999; i++) {
        int j = rever(i);
        if(check_1(i, j)) {
            if(i * 10000 + j == n) continue; // 跳过同一年的回文日期
            cout << i * 10000 + j << endl;
            break;
        }
    }
    for(int i = n / 10000; i <= 9999; i++) {
        int j = rever(i);
        if(check_2(i, j) && check_1(i, j)) {
            if(i * 10000 + j == n) continue;
            cout << i * 10000 + j << endl;
            break;
        }
    }
    return 0;
}