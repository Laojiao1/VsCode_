#include <bits/stdc++.h>
using namespace std;
struct student {
    int id; // 学号
    double score1; // 学业成绩
    double score2; // 素质拓展成绩
    double solve(double s1, double s2) {
        return 0.7*s1 + 0.3*s2;
    }
} stu[1001];

bool func_(struct student stu) {
    if((stu.score1 + stu.score2) > 140 && stu.solve(stu.score1, stu.score2) >= 80) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].id >> stu[i].score1 >> stu[i].score2;
    }
    for(int i = 1; i <= n; i++) {
        if(func_(stu[i])) {
            cout << "Excellent" << endl;
        } else {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}