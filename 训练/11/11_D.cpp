//如果满足题意，则第一组数中一定包含x或y
//然后找到与第一组完全不同的一组数
//如果满足题意，这组数中一定包含x或y
//然后遍历验证
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+7;
pair<int, int> p[maxn];
int n, m;


bool check(int a, int b) {
	for(int i = 1; i <= m; i++) {
		if(p[i].first != a && p[i].first != b 
           && p[i].second != a && p[i].second != b)
			return 0;
	}
	return 1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
    }
    int flag = 0;
    int a = p[1].first;
    int b = p[1].second;
    int c, d;
    for(int i = 2; i <= m; i++) {
        if(p[i].first != a && p[i].second != b
           && p[i].first != b && p[i].second != a) {
               flag = 1;
               c = p[i].first;
               d = p[i].second;
               break;
        }
    }
    if(flag == 0) {
        cout << "YES" << endl;
    } else {
        if(check(a, c) || check(a, d) || check(b, c) || check(b, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}