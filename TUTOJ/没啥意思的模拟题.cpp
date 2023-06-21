//TUTOJ 91
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
pair<long long, long long> a[5005];
bool cmp(pair<long long, long long>p1, pair<long long, long long>p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    } else {
        return p1.first < p2.first;
    }
}

int main() {   
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        a[i].first = b;
        a[i].second = i;
    }
    sort(a+1, a+1+n, cmp);
    int maxx = a[1].second;
    for(int i = 1; i <= n; i++) {
        if(a[i].first == a[i+1].first) {
            maxx = max(a[i].second, a[i+1].second);
        } else {
            break;
        }
    }
    cout << fabs(a[n].second - maxx) + 1 << endl;
    return 0;
}