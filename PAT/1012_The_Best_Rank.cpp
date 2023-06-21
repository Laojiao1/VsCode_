// 排序+离散化
#include <bits/stdc++.h>
using namespace std;
struct Student{
    int grade[4];
    int rank[4];
    int id;
}student[2000];
int id[1000000];
int compareGrade = -1;
bool cmp(Student a, Student b) {
	return a.grade[compareGrade] > b.grade[compareGrade];
}
int main() {
    freopen("in.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> student[i].id >> student[i].grade[1] >> student[i].grade[2] >> student[i].grade[3];
		student[i].grade[0] = (student[i].grade[1] + student[i].grade[2] + student[i].grade[3]) / 3;
	}
	for(int i = 0; i < 4; i++) {
		compareGrade = i;
		sort(student, student + n, cmp); // 对每个成绩进行排名 
		for(int j = 0; j < n; j++) {
			if(student[j].grade[i] == student[j-1].grade[i]) {
				student[j].rank[i] = student[j-1].rank[i];
			} else {
				student[j].rank[i] = j + 1;
			}
		}
	}
	// 离散化映射id
	fill(id, id + 100000, -1); // -1代表没有 
    // 初始化映射数组，-1代表此学生不存在
    fill(id, id + 1000000, -1);
	for(int i = 0; i < n; i++) {
		id[student[i].id] = i; 
	} 
	int search, index;
	char str[] = {'A', 'C', 'M', 'E'};
	for(int i = 0; i < m; i++) {
		cin >> search;
		index = id[search];
		if(index < 0) {
			cout << "N/A" << endl;
		} else {
			int top = 2001, topJ = 0;
			for(int j = 0; j < 4; j++) {
				if(student[index].rank[j] < top) {
					top = student[index].rank[j];
					topJ = j;
				} 
			}
			cout << top << " " << str[topJ] << endl;
		}
	}
	return 0;
} 