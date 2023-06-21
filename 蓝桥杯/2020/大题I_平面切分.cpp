// 先找出两条直线把这个平面一共分成了多少份
// 然后每加一条线遍历这条线与其他线一共有多少交点，增加的部分等于交点个数+1
// 注意去重
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
#define ll long long
typedef pair<long double,long double> p;
set<p> s;
set<p>::iterator it; 
int n, A[N], B[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }
    int i;
    for(i = 0, it = s.begin(); it != s.end(); it++, i++) {
        A[i] = (*it).first;
        B[i] = (*it).second;
    }
    ll ans = 2;
    set<p> se;
    for(int i = 1; i < n; i++) {
    	for(int j = i-1; j >= 0; j--) {
    		long double x=(B[j]-B[i])/(A[i]-A[j]);
			long double y=(A[j]*B[i]-A[i]*B[j])/(A[j]-A[i]);
			se.insert(make_pair(x, y));
    	}
    	int sum = se.size();
    	ans += (sum+1);
    	se.clear();
    }
    cout << ans << endl;
    return 0;
}
