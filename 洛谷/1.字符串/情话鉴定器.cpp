#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    while(1) {
        getline(cin, s);
        if(s == "Shu wan le") {
            break;
        }
        bool flag = 0;
        bool flag2 = 0;
        bool flag3 = 0;
        int pos = 0;
        if(flag == 0) {
            if(s.find('I') != string::npos) {
                flag = 1;
            }
            pos = s.find('I')+1;
        }
        if(flag2 == 0) {
            if(s.find("love", pos) != string::npos) {
                flag2 = 1;
            }
            pos = s.find("love", pos)+1;
        }
        if(flag3 == 0) {
            if(s.find("you", pos) != string::npos)
                flag3 = 1;
        }
        if(flag && flag2 && flag3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}