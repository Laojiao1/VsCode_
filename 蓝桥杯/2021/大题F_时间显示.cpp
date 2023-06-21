#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
    cin >> n;
    n /= 1000; // 换算成秒
    n = n % (24 * 3600); // 对一天的总秒数取余，选出当天时间的总秒数
    long long hour = n / 3600; // 算出小时
    long long minute = (n % 3600) / 60; // 算出分钟
    long long second = n % 60; // 算出秒数
    if(hour < 10) {
        cout << '0' << hour << ":";
    } else {
        cout << hour << ":";
    }
    if(minute < 10) {
        cout << '0' << minute << ":";
    } else {
        cout << minute << ":";
    }
    if(second < 10) {
        cout << '0' << second << endl;
    } else {
        cout << second << endl;
    }
    return 0;
}