// 题目名：樱花
// https://www.luogu.com.cn/problem/P1833
#include <iostream>
using namespace std;
const int maxn = 201;
int t[maxn], c[maxn], p[maxn], f[maxn];
int a, b;
char ch;
int n;
int pre[10];
int main() {
    int cnt = 1;
    for(int i = 1; i <= 2; i++) {
        cin >> a >> ch >> b;
        pre[cnt] = a*60+b;
        cnt++;
    }
    int time = pre[2] - pre[1];
    // cout << time << endl;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i] >> p[i];
    }
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) { // 完全背包
            for(int j = t[i]; j <= time; j++)
    	        f[j] = max(f[j] , f[j-t[i]] + c[i]) ;
        } else { // 转换成01背包
            for(int j = 1 ; j <= p[i] ; j ++) { // 遍历次数
		        for(int l = time; l >= t[i] ; l--) {
			        f[l] = max(f[l], f[l-t[i]]+c[i]);
		        }
            }
        }
    }
    cout << f[time];
    return 0;
}