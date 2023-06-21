// https://www.luogu.com.cn/problem/P1908
// https://blog.csdn.net/qq_41431457/article/details/88945833
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct Node {
    int val;
    int id;
} a[N];
int n, Tree[N], ranks[N]; // rank[i]用来存放第i大的数在原数组中的位置 
// 例如 rank[4] = 1 代表第1大的数组在原数组中的位置是第4个
long long ans;
bool cmp(Node a1, Node a2) {
	if(a1.val == a2.val) return a1.id > a2.id;
	return a1.val > a2.val;
}
int lowbit(int x) {
    return x & -x;
}
void add(int i, int k) {
    for(; i <= n; i += lowbit(i)) {
        Tree[i] += k;
    }
}
int sum(int i) {
    int sum = 0;
    for(; i > 0; i -= lowbit(i)) {
        sum += Tree[i];
    }
    return sum;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i].val;
		a[i].id = i; 
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++) {
    	ranks[a[i].id] = i;
    }
    for(int i = 1; i <= n; i++) {
    	add(ranks[i], 1);
    	ans += sum(ranks[i]-1);
    }
    printf("%lld", ans);
    return 0;
}