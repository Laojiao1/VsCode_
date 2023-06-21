#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
struct Node {
    char name[10];
    int age, worth;
} p[N];
bool cmp(Node a1, Node a2) {
    if(a1.worth != a2.worth) {
        return a1.worth > a2.worth;
    } else if(a1.age != a2.age) {
        return a1.age < a2.age;
    } else {
        return strcmp(a1.name, a2.name) < 0;
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].age >> p[i].worth;
    }
    sort(p, p + n, cmp);
    for(int i = 0; i < k; i++) {
        int x, Amin, Amax;
        cin >> x >> Amin >> Amax;
        printf("Case #%d:\n", i+1);
        int cnt = 0, j = 0;
        while(cnt < x && j < n) {
            if(p[j].age < Amin || p[j].age > Amax) {
                j++;
                continue;
            }
            cout << p[j].name << " " << p[j].age << " " << p[j].worth << endl;
            cnt++, j++;
        }
        if(cnt == 0) {
            cout << "None" << endl;
        }
    }
    return 0;
}