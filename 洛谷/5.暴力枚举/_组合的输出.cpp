// P1157
// 在1-n个元素中取r个数进行排列组合，从小到大输出
// 要求：所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，
// 每个元素占三个字符的位置，所有的组合也按字典顺序。
// 首先是厚颜无耻的STL大法！！！
#include <bits/stdc++.h>
using namespace std;
int x[30];//x[i]代表第i选或不选，0代表选，1代表不选
int main() {
    int n, r;
    scanf("%d %d", &n, &r);//读入n、r, 用scanf能节省多少时间节省多少时间
    for(int i = r+1; i <= n; ++i)
        x[i] = 1; //赋初始值
    do {
        for(int i = 1; i <= n; ++i)
            if(x[i] == 0) printf("%3d", i);//如果是0就输出，注意三个常宽
        printf("\n");//换行
    } while(next_permutation(x+1, x+n+1));//生成下一个
    return 0;//返回
}

// 下面是回溯+搜索做法, 与全排列问题的思路差不多，但要注意判断条件
#include <bits/stdc++.h>//万能头文件
using namespace std;
int n, r;
int total = 0;
bool pd[50];
int used[50];
void print() {
    for(int i = 1; i <= r; i++) {
        cout << setw(3) << used[i];
    }
    cout << endl;
}
void dfs(int k) {
    int i;
    if(k > r) {
        print();
        return;
    }
    for(int i = 1; i <= n; i++) { // 枚举每一个数
        if(!pd[i] && i > used[k-1] || k == 1) { // 与全排列问题唯一不同的就是判断条件
            // 当i没有被使用过且i必须大于前个数但除1之外
            pd[i] = 1; // 标记已用过的数
            used[k] = i; // 将满足条件的数存到数组中
            dfs(k+1); // 继续搜索
            // 回溯
            pd[i] = 0;
        }
    }
}
int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}