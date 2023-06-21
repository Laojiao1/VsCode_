#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
queue<int> qu; // 推送器队列
stack<int> sta, stb; // sta: 松枝 ,stb:盒子
vector<vector<int>> ans; // 答案数组
int n, m, k;
void my_insert() {
    vector<int> ret;
    while(sta.size() != 0) {
        ret.push_back(sta.top());
        sta.pop();
    }
    reverse(ret.begin(), ret.end());
    ans.push_back(ret);
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m >> k; // 推送器松针片，盒子中松针片，一支松叶片能插松针的数量
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        qu.push(num);
    }

    while(!qu.empty() || !stb.empty()) {
        if(!stb.empty()) {
            int top = stb.top();
            // 如果小盒子的数据满足要求，就加入到松树枝中
            if(sta.size() == 0 || top <= sta.top()) {
                sta.push(top);
                stb.pop();
                // 如果插满了，就记录答案
                if(sta.size() == k) {
                    my_insert();
                }
                //如果小盒子里的数据不满足，并且推送器里还有松针
            } else if(top > sta.top() && qu.size() != 0) {
                int temp = qu.front();
                if(temp <= sta.top()) {
                    sta.push(temp);
                    qu.pop();
                    // 如果此松叶插满了，就将其放入到答案中
                    if(sta.size() == k) {
                        my_insert(); 
                    }
                } 
                // 如果推送器上的不满足要求
                else if(temp > sta.top()) {
                    if(stb.size() < m) {
                        stb.push(temp);
                        qu.pop();
                    } else {
                        my_insert();
                    }
                }
                // 如果盒子数据不满足且推送器里没有松针了
            } else if(top > sta.top() && qu.size() == 0) {
                my_insert();
            }
        }
        // 如果小盒子里为空，但是推送器里不为空，从推送器里拿
        else if(stb.size() == 0 && qu.size() != 0) {
            int t = qu.front();
            if(sta.size() == 0 || t <= sta.top()) {
                sta.push(t);
                if(sta.size() == k) {
                    my_insert();
                }
                qu.pop();
            }
            // 如果推送器上的不满足
            else if(t > sta.top()) {
                stb.push(t);
                qu.pop();
            }
        }
    }
    if(sta.size() != 0) {
        my_insert();
    }
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            if(j != ans[i].size() - 1) cout << ans[i][j] << " ";
            else cout << ans[i][j] << endl;
        }
    }
    return 0;
}