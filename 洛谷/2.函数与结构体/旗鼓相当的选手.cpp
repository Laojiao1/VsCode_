#include <bits/stdc++.h>
using namespace std;
struct score {
    string name;
    int chinese = 0;
    int math = 0;
    int english = 0;
    int sum_socre = 0;
} stu[1001];

bool cmp(struct score stu1, struct score stu2) {
    return stu1.name < stu2.name;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].name
            >> stu[i].chinese
            >> stu[i].math
            >> stu[i].english;
        stu[i].sum_socre = stu[i].english + stu[i].math + stu[i].chinese;
    }
    sort(stu+1, stu+1+n, cmp);
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(abs(stu[i].chinese - stu[j].chinese) <= 5 && 
                abs(stu[i].math - stu[j].math) <= 5 &&
                abs(stu[i].english - stu[j].english) <= 5 &&
                abs(stu[i].sum_socre - stu[j].sum_socre) <= 10) {
                    cout << stu[i].name << " " << stu[j].name << endl;
            }
        }
    }
    return 0;
}