// 注意去重
#include <bits/stdc++.h>
using namespace std;
int temp = 0;
bool Begin[7800];// 记录月初
bool Monday[7800]; // 周一
const int arr1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int arr2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 闰年：能被4整除但不能被100整除；能被400整除
bool isRunNian(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}
int func() { // 返回从2000.1.1周六到2020.10.1周四,一共有几个周一和月初（有多少天多跑了）
    int yuechu = 12 * 20 + 10; // 月初
    // 计算周一的天数
    // 直接循环对7取余就行
    int cnt_day = 0;
    int cnt_ans = 0;
    int week = 6;
    while(1) {
        cnt_day++; // 计算天数
        if(week % 7 == 1) {
            cnt_ans ++;
            Monday[cnt_day] = 1;
        }
        week = (week + 1) % 7;
        if(cnt_day == temp) { // 如果遍历完了所有天数，直接退出循环
            break;
        }
    }
    //cout << cnt_ans << " " << yuechu << endl;
    return cnt_ans + yuechu;
}
// 去重
int Deduplication() {
    // 标记月初
    int ans = 0;
    int cnt_day = 1;
    int curYear = 2000;
    Begin[1] = 1;
    while(1) {
        if(isRunNian(curYear)) {
            for(int i = 0; i < 12; i++) {
                cnt_day += arr1[i];
                Begin[cnt_day] = 1;
            }
        } else {
            for(int i = 0; i < 12; i++) {
                cnt_day += arr2[i];
                Begin[cnt_day] = 1;
            }
        }
        curYear++;
        if(curYear == 2022) break; 
    }
    for(int i = 1; i <= temp; i++) {
        if(Begin[i] == 1 && Monday[i] == 1) ans++;
    }
    return ans;
}
int main() {
    int Leap_year = 0, Normal_year = 0;
    // if(isRunNian(2020)) cout << "Yes" << endl;
    // else cout << "No" << endl;
    for(int i = 2000; i <= 2019; i++) {
        if(isRunNian(i)) Leap_year++;
    }
    Normal_year = (2019 - 2000 + 1) - Leap_year;
    temp = Leap_year * 366 + Normal_year * 365 + (366-31-30-31+1); // 不算多跑的一公里
    cout << temp + func() - Deduplication() - 3 << endl;
    return 0;
}