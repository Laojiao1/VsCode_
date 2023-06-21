// 时间还是不够优化...
// 题不难
#include <bits/stdc++.h>
using namespace std;
using iter = set<int>::iterator;
int q;
set<int> st;
int main() {
    cin >> q;
    ios::sync_with_stdio(false);
    for(int i = 1; i <= q; i++) {
        int choice, num;
        cin >> choice >> num;
        if(choice == 1) {
            if(!st.insert(num).second) {
                cout << "Already Exist" << endl;
            }
        } else {
            if(st.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            if(st.find(num) != st.end()) {
                cout << num << endl;
                st.erase(num);
            } else {
                iter pos;
                pos = st.lower_bound(num);
                if(pos == st.begin()) {
                    cout << *pos << endl;
                    st.erase(pos);
                } else {
                    auto pos1 = prev(pos, 1);
                    int num1 = *pos - num;
                    int num2 = num - *pos1;
                    if(num1 == num2) {
                        cout << *pos1 << endl;
                        st.erase(pos1);
                    } else if(num1 < num2) {
                        cout << *pos << endl;
                        st.erase(pos);
                    } else {
                        cout << *pos1 << endl;
                        st.erase(pos1);
                    }
                }
            }
        }
    }
    return 0;
}