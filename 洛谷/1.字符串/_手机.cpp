#include <bits/stdc++.h>
using namespace std;
int num[26] = {1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4};
int main() {
    string s;
    getline(cin, s);
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            cnt += num[s[i]-'a'];
        }
        if(s[i] == ' ') cnt++;
    }
    cout << cnt << endl;
    return 0;
}

// 法二 STL大法
// map也很好用(就是有点费手指orz)
// #include <bits/stdc++.h>
// using namespace std;
// map<char,int> ma;//定义map，把char类型转化成int
// string word;
// int ans = 0;
// void init()
// {
//     ma['a']=1;
//     ma['b']=2;
//     ma['c']=3;
//     ma['d']=1;
//     ma['e']=2;
//     ma['f']=3;
//     ma['g']=1;
//     ma['h']=2;
//     ma['i']=3;
//     ma['j']=1;
//     ma['k']=2;
//     ma['l']=3;
//     ma['m']=1;
//     ma['n']=2;
//     ma['o']=3;
//     ma['p']=1;
//     ma['q']=2;
//     ma['r']=3;
//     ma['s']=4;
//     ma['t']=1;
//     ma['u']=2;
//     ma['v']=3;
//     ma['w']=1;
//     ma['x']=2;
//     ma['y']=3;
//     ma['z']=4;
//     ma[' ']=1;
// }

// int main()
// {
//     init();
//     getline(cin,word);//读入
//     for(int i=0;i<word.length();i++)
//     {
//         ans+=ma[word[i]];
//     }
//     cout<<ans<<endl;
// }