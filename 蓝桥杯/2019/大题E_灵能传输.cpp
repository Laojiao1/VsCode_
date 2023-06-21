// 思维题，脑筋急转弯orz
// 首先题目最终转换为让相邻前缀和之差的最大值最小即ans=max{ ( |s1-s0|,|s2-s1|…|sn-sn-1| ) }
// 然后我们要知道导致不稳定度大的原因是什么。观察后可以发现，不稳定度大的原因很可能是因为点的分布不均匀导致。
// 例如序列：0、-1 、-2、-4、-5、-2、1、5、3、2。我们会发现从s0 = 0开始到min = -5间的点十分密集而从min = -5到sn = 2间的点却十分稀疏。而点的分布越是稀疏，相邻前缀和间的差值往往越大于是使用贪心的思想我们就需要使用某种策略使得点的分布均匀起来这样可以使得相邻前缀和间的差值可以趋于中庸也就是我们所需要的最优解。
// 而这种策略便是视频中所说的排序后记录下s0,s1的位置，分别从s0和s1开始隔一个跳一次的将数值存入res数组中即可得到最优点的分布，最终点的分布一定是尽可能均匀的。
#include <bits/stdc++.h>
using namespace std;
#define maxn 300005
typedef long long ll;
ll s[maxn], res[maxn];
bool v[maxn];
int t, n;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        memset(s, 0, sizeof(s));
        memset(res, 0, sizeof(res));
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= n; ++i) {
            cin >> s[i];
            s[i] += s[i-1];
        }
        ll s0 = s[0], s1 = s[n];
        if(s0 > s1) swap(s0, s1);
        sort(s, s+1+n);
        for(int i = 0; i <= n; i++) {
            if(s0 == s[i]) {
                s0 = i;
                break;
            }
        }
        for(int i = 0; i <= n; i++) {
            if(s1 == s[i]) {
                s1 = i;
                break;
            }
        }
        int l = 0, r = n;
        for(int i = s0; i >= 0; i-=2) {
            res[l++] = s[i];
            v[i] = 1;
        }
        for(int i = s1; i <= n; i+=2) {
            res[r--] = s[i];
            v[i] = 1;
        }
        for(int i = 0; i <= n; i++) {
            if(!v[i]) {
                res[l++] = s[i];
                v[i] = 1;
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, abs(res[i] - res[i-1]));
        }
        cout << ans << endl;
    }

    return 0;
}
