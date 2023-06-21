// 总结：
// substr() 生成字串，输入位置和长度
// s.insert(a, b) 插入s中以位置a起始后b个字符
// find(str,position) str:要找的元素，position:从那个位置开始找（可以不填，默认从0开始）
// 返回值为最早出现目标字符的位置，当没有找到目标字符时返回string::npos
#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;
int main() {
    int t;
    cin >> t;
    cin >> s1;
    for(int i = 0; i < t; i++) {
        int num;
        cin >> num;
        if(num == 1) {
            cin >> s2;
            s1 += s2;
            cout << s1 << endl;
        } else if(num == 2) {
            int a, b;
            cin >> a >> b;
            s1 = s1.substr(a, b); //生成子串，输入位置和长度
            cout << s1 << endl;
        } else if(num == 3) {
            int c;
            cin >> c >> s2;
            s1.insert(c, s2);//在s1中c处位置插入s2
            cout << s1 << endl;
        } else if(num == 4) {
            cin >> s2;
            if(s1.find(s2) < s1.size()) {//查找字符串中某个字符串的位置并返回他的位置
                cout << s1.find(s2) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}