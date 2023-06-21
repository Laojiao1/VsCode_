// 水题
#include <bits/stdc++.h>
using namespace std;
struct student {
    double chinese;
    double math;
    double english;
    double sum;  
    int id; 
} stu[303];
int n;
bool cmp(struct student s1, struct student s2) {
    if(s1.sum != s2.sum) {
        return s1.sum > s2.sum;
    } else {
        if(s1.chinese != s2.chinese) {
            return s1.chinese > s2.chinese;
        } else {
            return s1.id < s2.id;
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
        stu[i].id = i;
    }
    sort(stu+1, stu+1+n, cmp);
    for(int i = 1; i <= 5; i++) {
        cout << stu[i].id << " " << stu[i].sum << endl;
    }
    return 0;
}