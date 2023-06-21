// P1249
// 贪心， 高精度乘法的应用
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50001;
int a[maxn], b[maxn], ans[maxn];
int n;
vector<int> F;
vector<string> C;
// 高精度乘法
string mul(string s1, string s2) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(a));
    memset(ans, 0, sizeof(a));
    int len_a, len_b, len_ans;
    string ret;
    len_a = s1.length();
    len_b = s2.length();
    len_ans = len_a + len_b;
    for(int i = 1, j = len_a-1; i <= len_a; i++, j--) {
        a[i] = s1[j] - '0';
    }
    for(int i = 1, j = len_b-1; i <= len_b; i++, j--) {
        b[i] = s2[j] - '0';
    }
    for(int i = 1; i <= len_a; i++) {
        for(int j = 1; j <= len_b; j++) {
            ans[i+j-1] += a[i] * b[j];
            ans[i+j] += ans[i+j-1] / 10;
            ans[i+j-1] %= 10;
        }
    }
    while(len_ans > 1 && ans[len_ans] == 0) len_ans--;
    while(len_ans >= 1) ret += ans[len_ans--] + '0';
    return ret;
}

void find() {
    int sum = 0;
    for(int i = 2; i < n; i++) {
        if(sum + i > n) {
            int rm = n - sum;
            while(rm) {
                for(int j = F.size()-1; j >= 0 && rm > 0; j--) {
                    F[j]++;
                    rm--;
                }
            }
            return;
        }
        sum += i;
        F.push_back(i);
    }
}

int main() {
    cin >> n;
    if(n == 3) {
        cout << "1 2" << endl;
        cout << "2" << endl;
    } else if(n == 4) {
        cout << "1 3" << endl;
        cout << "3" << endl;
    } else {
        find();
        for(int i = 0; i < F.size(); i++) {
            string ch = to_string(F[i]); // 把一个整数转换为string类型
            C.push_back(ch); // 把每一个数都变成字符放进容器中
        }
        // for(int i = 0; i < C.size(); i++) {
        //     cout << C[i] << " ";
        // }
        string ans = "1";
        for(int i = 0; i < C.size(); i++) {
            ans = mul(ans, C[i]);
            cout << C[i] << " ";
        }
        cout << endl;
        cout << ans << endl;
    }
    
    return 0;
}