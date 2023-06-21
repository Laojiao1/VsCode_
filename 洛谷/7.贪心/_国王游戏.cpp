// 偏向思维数学题 ：如何贪心？
// 一道绿题，值得思考
// 此外这道题还要用到高精度emmm
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int MaxN = 10010;
struct Node {
    int l, r;
} a[MaxN];
int n;
int pro[MaxN], temp[MaxN], ans[MaxN];
bool cmp(Node a1, Node a2) {
    return a1.l * a1.r < a2.l * a2.r;
}
void div(int *aa, int *bb, int num){ // 除法
    memset(bb, 0, sizeof(bb));
    int x = 0;
    for(int i = MaxN - 1; i >= 0; i--) {
        x = x * 10 + aa[i];
        bb[i] = x / num;
        x %= num;
    }
}
void mul(int *aa, int num) {
    for(int i = MaxN-2; i >= 0; i--) aa[i] *= num; // 先把每一位数都乘上
    for(int i = 0; i < MaxN-1; i++) {
        aa[i+1] += (aa[i] / 10); //进位
        aa[i] %= 10;
    }
}
bool more(int *aa, int *bb) { // 比较大小
    for(int i = MaxN-1; i >= 0; i--) {
        if(aa[i] > bb[i]) return 1;
        if(aa[i] < bb[i]) return 0;
    }
    return 0;
}
void copy(int *aa, int *bb) {
    for(int i = 0; i < MaxN; i++) {
        aa[i] = bb[i];
    }
}
void print(int *aa) {
    bool flag = 0;//用来判断前导0
    for(int i = MaxN-1; i >= 0; i--) {
        if(!flag) {
            if(aa[i]) flag = 1; // 找到第一个不是0的位，就可以输出了
            else continue;// 否则的话继续寻找
        } // 判断前导0
        cout << aa[i];
    }
}
int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a+1, a+1+n, cmp);
    pro[0] = 1;
    for(int i = 0; i <= n; i++) {
        div(pro, temp, a[i].r); // 先除到temp上，方便比较
        if(more(temp, ans)) copy(ans, temp); //如果满足就复制过来
        mul(pro, a[i].l); // 继续乘下去
    }
    // 输出
    print(ans);
    return 0;
}