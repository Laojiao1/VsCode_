// STL 中map可以轻松实现
// find(key) 查找key是否存在，返回该键元素的迭代器；若不存在，返回.end()
#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
map<char, int>::iterator p, mEnd;
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        p = mp.find(s[i]); 
        if(p != mp.end()) {
            p->second++;
        } else {
            mp.insert(pair<char, int>(s[i], 1));
        }
    }
    p = mp.begin();
    mEnd = mp.end();
    for( ; p != mEnd; p++) {
        cout << p->first << " : " << p->second << endl;
    }
    return 0;
}