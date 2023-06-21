// 模拟题
// 使用map容器比较好做
// a.count(x)	判断x为下标的元素是不是在a中，是就返回1，不是就返回0
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n;
int main() {
    cin >> n;
    ios::sync_with_stdio(false);
    while(n--) {
        int select;
        string name;
        cin >> select;
        if(select == 1) {
            int score;
            cin >> name >> score;
            mp[name] = score; // 直接赋值
            cout << "OK" << endl;
        } else if(select == 2) {
            cin >> name;
            if(mp.count(name)) { // 判断x为下标的元素是不是在a中，是就返回1，不是就返回0
                cout << mp[name] << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if(select == 3) {
            cin >> name;
            if(mp.count(name)) {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else {
            cout << mp.size() << endl;
        }
    }
    return 0;
}