#include <bits/stdc++.h>
using namespace std;
const int arr1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平
const int arr2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰
int arr[8000];
int arrr[8000];
bool is_run_year(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int sum_day = 0; // 总共的天数
    for(int i = 2000; i <= 2019; i++) {
        if(is_run_year(i)) {
            sum_day += 366;
        } else {
            sum_day += 365;
        }
    }
    sum_day += 275;
    int first_month_day = 12*20 + 10; // 总共的月初天数

    int cur_day = 0;
    int Monday_cnt = 0; // 周一的天数
    int week = 6;
    while(1) {
        cur_day++;
        if(week % 7 == 1) {
            Monday_cnt ++;
            arr[cur_day] = 1; // 标记周一的天数
        }
        week = (week + 1) % 7;
        if(cur_day == sum_day) break;
    }

    // 去重，计算既是月初也是周一
    int cur_year = 2000;
    int repeat_day = 0;
    cur_day = 1;
    arrr[1] = 1;
    while(1) {
        if(is_run_year(cur_year)) {
            for(int i = 0; i < 12; i++) {
                cur_day += arr2[i];
                arrr[cur_day] = 1;
            }
        } else {
            for(int i = 0; i < 12; i++) {
                cur_day += arr1[i];
                arrr[cur_day] = 1;
            }
        }
        cur_year++;
        if(cur_year == 2022) break;
    }
    for(int i = 1; i <= sum_day; i++) {
        if(arr[i] == 1 && arrr[i] == 1) repeat_day++;
    }
    cout << sum_day + first_month_day + Monday_cnt - repeat_day << endl;
    return 0;
}