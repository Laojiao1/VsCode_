// https://www.luogu.com.cn/problem/P1040
// 区间Dp
#include <bits/stdc++.h>
using namespace std;
const int N = 50;
typedef long long ll;
ll n, f[N][N], root[N][N];
// f[i][j]表示i结点到j结点所组成的最大加分二叉树
// root[i][j]表示结点i到结点j所成的最大加分二叉树所选的结点
void print(int l, int r) {
	if(l > r) return;
	if(l == r) {
		cout << root[l][r] << " ";
		return;
	}
	cout << root[l][r] << " ";
	print(l, root[l][r]-1);
	print(root[l][r]+1, r);
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i][i];
        f[i][i-1] = 1; // 空树设为1
        root[i][i] = i; // 初始化
    }
    for(int len = 2; len <= n; len++) { // 枚举区间
        for(int l = 1; l + len - 1 <= n; l++) { // 枚举结点
            int r = l + len - 1;
            for(int k = l; k < r; k++) { // 枚举根节点
                if(f[l][r] < f[l][k-1] * f[k+1][r] + f[k][k]) {
                    f[l][r] = f[l][k-1] * f[k+1][r] + f[k][k];
                    root[l][r] = k;
                }
            }
        }
    }
    cout << f[1][n] << endl;
    print(1, n);
    return 0;
}