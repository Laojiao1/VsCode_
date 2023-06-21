#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string s;
    char ch[101];
    char ch1[101];
    long long int x;
    int j;
    getline(cin, s);
    if(s[0] == '0' && s.length() == 1) {
        cout << 0 << endl;
    }
    if(s.find('.') == string::npos && s.find('/') == string::npos
        && s.find('%') == string::npos) {
        int pos = s.length()-1;
        while(s[pos] == '0') {
            pos--;
        }
        for(int i = pos; i >= 0; i--)
            cout << s[i];
    } else {
        if(s[s.length()-1] == '%') {
            int pos = s.length()-2;
            while(s[pos] == '0') {
                pos--;
            }
            for(int i = pos; i >= 0; i--)
                cout << s[i];
            cout << '%';
        } else {
            if(s.find('.') != string::npos) {
                int pos = s.find('.');
                for(int i = pos-1, j = 0; i >= 0; i--, j++) {
                    ch[j] = s[i];
                }
                int x = atoi(ch);
                if(s[pos+1] == '0' && s[pos+2] == '\0') {
                    cout << x << ".0";
                    exit(0);
                } else {
                    cout << x << '.';
                }
                for(int i = s.length()-1, j = 0; i > pos; i--, j++) {
                    ch1[j] = s[i];
                }
                x = atoi(ch1);
                while(x % 10 == 0) {
                    x /= 10;
                }
                cout << x << endl;
            }
            if(s.find('/') != string::npos) {
                int pos = s.find('/');
                for(int i = pos-1, j = 0; i >= 0; i--, j++) {
                    ch[j] = s[i];
                }
                int x = atoi(ch);
                cout << x << '/';
                for(int i = s.length()-1, j = 0; i > pos; i--, j++) {
                    ch1[j] = s[i];
                }
                x = atoi(ch1);
                while(x % 10 == 0) {
                    x /= 10;
                }
                cout << x << endl;
            }
        }
    }
    return 0;
}