// P1098
// 模拟题
// 熟练掌握STL大法

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int p1, p2, p3;
    string s;
    cin >> p1 >> p2 >> p3 >> s;
    for(int i = 1; i < s.length()-1; i++) {
        if(s[i] == '-' && ( (islower(s[i-1]) && islower(s[i+1]) && s[i-1]<s[i+1]) 
            || (isdigit(s[i-1]) && isdigit(s[i+1]) && s[i-1]<s[i+1]) ) ) {
            if(p1 == 1) {
                s.erase(i, 1);//删去'-'
                string t = ""; //临时空字符串
                for(int j = s[i-1]+1; j <= s[i]-1; j++) {
                    char ch = j;
                    for(int k = 1; k <= p2; k++) t.push_back(ch); // 插入p2个字符
                }
                    if(p3 == 2) reverse(t.begin(), t.end()); // 翻转
                    s.insert(i, t); //最后插入原字符串中
            } else if(p1 == 2) {
                s.erase(i, 1);
                string t = "";
                for(int j = s[i-1]+1; j <= s[i]-1; j++) {
                    char ch = j;
                    ch = toupper(ch);// 把小写转换为大写
                    for(int k = 1; k <= p2; k++) t.push_back(ch); 
                }
                    if(p3 == 2) reverse(t.begin(), t.end());
                    s.insert(i, t);
            } else if(p1 == 3) {
                s.erase(i, 1);
                string t = "";
                for(int j = s[i-1]+1; j <= s[i]-1; j++)
                    for(int k = 1; k <= p2; k++) t.push_back('*');
                if(p3 == 2) reverse(t.begin(), t.end());
                s.insert(i, t);
            }
        }
    }
    cout << s << endl;
    return 0;
}