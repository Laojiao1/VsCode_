//STL知识——string库
//tolower() 都转换为小写字母
//getline(cin, str); 直接读入一整行
//find(str,position) str:要找的元素，position:从那个位置开始找（可以不填，默认从0开始）
//返回值为最早出现目标字符的位置，当没有找到目标字符时返回string::npos(-1)


//本题技巧：在字符串前后都加一个空格
//PS：不要忘记用两个getline输入，防止误输入换行！
//    遍历字符串时结尾是\0

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
    }
    for(int i = 0; i < s2.length(); i++) {
        s2[i] = tolower(s2[i]);
    }
    s1.insert(0, " ");
    s1 += ' ';
    s2.insert(s2.begin(), ' ');
    s2 += ' ';
    if(s2.find(s1) == string::npos) {
        cout << -1 << endl;
    } else {
        int sum = 0;
        int n = 0;
        while(s2.find(s1, n) != string::npos) {
            sum++;
            n = s2.find(s1, n) + 1;
        }
        cout << sum << " " << s2.find(s1) << endl;
    }
    return 0;
}
