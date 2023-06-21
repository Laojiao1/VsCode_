// 水题
#include <bits/stdc++.h>
using namespace std;
struct Person{
    int id;
    int time;
} p[1001];
bool cmp(Person p1, Person p2) {
    return p1.time < p2.time;
}
int main() {
    int n;
    cin >> n;
    double sum = 0;
    for(int i = 1; i <= n; i++) {
        p[i].id = i;
        cin >> p[i].time;
    }
    sort(p+1, p+1+n, cmp);
    for(int i = 1; i <= n; i++) {
        cout << p[i].id << " ";
        sum += p[i].time * (n - i);
    }
    cout << endl;
    printf("%.2lf", sum/n);
    return 0;
}