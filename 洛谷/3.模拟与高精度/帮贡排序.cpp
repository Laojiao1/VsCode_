// P1786
// 排序是个大问题！
#include <bits/stdc++.h>
using namespace std;
struct bp {
    string name;
    string job;
    long long ctn;
    long long level;
    long long id;
} Person[520];
int pd(string a) {//将职位转换的函数
    if (a == "BangZhu") return 1;
    if (a == "FuBangZhu") return 2;
    if (a == "HuFa") return 3;
    if (a == "ZhangLao") return 4;
    if (a == "TangZhu") return 5;
    if (a == "JingYing") return 6;
    if (a == "BangZhong") return 7;
}

bool cmp1(struct bp p1, struct bp p2) {
    if(p1.ctn != p2.ctn) {
        return p1.ctn > p2.ctn;
    } else {
        return p1.id < p2.id;
    }
}

bool cmp2(struct bp p1, struct bp p2) {
    if(pd(p1.job) != pd(p2.job)) {
        return pd(p1.job) < pd(p2.job);
    } else {
        if(p1.level != p2.level) return p1.level > p2.level;
        else return p1.id < p2.id;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> Person[i].name >> Person[i].job
            >> Person[i].ctn >> Person[i].level;
        Person[i].id = i;
    }
    sort(Person+4, Person+1+n, cmp1);
    // for(int i = 1; i <= n; i++) {
    //     cout << Person[i].name << " " << Person[i].job << " "
    //          << Person[i].ctn << " " << Person[i].level << " "
    //          << Person[i].id << endl;
    // }
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            if(Person[i].job != "BangZhu") Person[i].job = "BangZhu";
        } else if(i >= 2 && i <= 3) { 
            if(Person[i].job != "FuBangZhu") Person[i].job = "FuBangZhu";
        } else if(i >= 4 && i <= 5) {
            if(Person[i].job != "HuFa") Person[i].job = "HuFa";
        } else  if( i >= 6 && i <= 9) {
            if(Person[i].job != "ZhangLao") Person[i].job = "ZhangLao";
        } else if(i >= 10 && i <= 16) {
            if(Person[i].job != "TangZhu") Person[i].job = "TangZhu";
        } else if(i >= 17 && i <= 41) {
            if(Person[i].job != "JingYing") Person[i].job = "JingYing";
        } else if(i >= 42) {
            if(Person[i].job != "BangZhong") Person[i].job = "BangZhong";
        }
    }
    sort(Person+1, Person+1+n, cmp2);
    for(int i = 1; i <= n; i++) {
        cout << Person[i].name << " " << Person[i].job << " "
             << Person[i].level << endl;
    }
    return 0;
}