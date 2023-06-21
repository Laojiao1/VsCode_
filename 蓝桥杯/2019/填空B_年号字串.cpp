#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int main() {
    int n;
    cin >> n;
    string s = "";
    while(n) {
        int num = n % 26;
        s += num + 'A' - 1;
        n /= 26;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}