#include <bits/stdc++.h>
using namespace std;
struct score {
    string name;
    int chinese = 0;
    int math = 0;
    int english = 0;
    int sum_socre = 0;
} stu[1001];
int main() {
    int n;
    cin >> n;
    int maxscore = -1;
    int maxi;
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].name
            >> stu[i].chinese
            >> stu[i].math
            >> stu[i].english;
        stu[i].sum_socre = stu[i].english + stu[i].math + stu[i].chinese;
    }
    for(int i = 1; i <= n; i++) {
        if(stu[i].sum_socre > maxscore) {
            maxscore = stu[i].sum_socre;
            maxi = i;
        }
    }
    cout << stu[maxi].name << " "
         << stu[maxi].chinese << " "
         << stu[maxi].math << " "
         << stu[maxi].english << endl;
    return 0;
}