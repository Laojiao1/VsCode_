// TUTOJ 132
#include<bits/stdc++.h>
using namespace std;
int t, n;
map<string ,int> flag;
queue<string> pig[1001];
int main(){
    cin >> t >> n;
    while (t--){
        int num;
        cin >> num;
        if(num == 0) {
            int flag;
            string a;
            cin >> flag >> a;
            pig[flag].push(a);
        }
        if(num ==1) {
            int flag1;
            cin >> flag1;
            if(pig[flag1].empty()) {
                cout << "Error!" << endl;
            } else {
                string name = pig[flag1].front();
                if(flag[name] == 1)
                    cout << "Gun! "<< name << endl;
                else{
                    flag[name] = 1;
                    cout << "Have fun! " << name <<endl;
                }
                pig[flag1].pop();
            }
        }
    }
}