#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int age;
	int score;
} stu[100001];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> stu[i].name >> stu[i].age >> stu[i].score;
	}
    for(int i = 1; i <= n; i++) {
        stu[i].age++;
        stu[i].score += stu[i].score*0.2;
        if(stu[i].score >= 600) {
            stu[i].score = 600;
        }
        cout << stu[i].name << " " << stu[i].age << " " << stu[i].score << endl;
    }
    return 0;
}