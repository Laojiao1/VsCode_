#include <bits/stdc++.h>
using namespace std;
int map[1010][1010];
int main() {
    int n, x1, x2, y1, y2, x, y;
    int flag = 0;
    cin >> n >> x1 >> y1
        >> x2 >> y2 >> x >> y;
    if( x2 < x1 && y2 > y1 && x < x1 && y > y1 || 
        x2 < x1 && y2 < y1 && x < x1 && y < y1 || 
        x2 > x1 && y2 > y1 && x > x1 && y > y1 || 
        x2 > x1 && y2 < y1 && x > x1 && y < y1) {
            flag = 1;
        }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;    
}
