#include <bits/stdc++.h>
using namespace std;
int word[26];
int main() {
    int maxx = -1;
    for(int i = 1; i <= 4; i++) {
        string s;
        getline(cin, s);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                word[s[i]-'A'] ++;
            }
        }
    }
    // for(int i = 0; i < 26; i++) cout << word[i] << " ";
    for(int i = 0; i < 26; i++) {
        maxx = max(maxx, word[i]);
    }
    for(int i = maxx; i > 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(word[j] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
    return 0;
}