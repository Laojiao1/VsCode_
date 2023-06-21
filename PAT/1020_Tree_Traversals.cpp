// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1001;
// vector<int> post, inor;
// void func(vector<int> inor, vector<int> post) {
//     if(post.empty()) return;
//     int root = post[post.size()-1];
//     cout << root;
//     //int pos = find(inor.begin(), inor.end(), root) - inor.begin();
//     vector<int>::iterator pos = find(inor.begin(), inor.end(), root);
//     post.pop_back();

//     vector<int> leftpost, rightpost;
//     vector<int>::const_iterator First = post.begin();  
//     vector<int>::const_iterator Second = post.begin() + *pos;
//     vector<int>::const_iterator End = post.end(); 
//     // leftpost.assign(post.begin(), pos-1);
//     // rightpost.assign(pos, post.end());
//     leftpost.assign(First, Second-1);
//     rightpost.assign(Second, End);

//     vector<int> leftinor, rightinor;
//     vector<int>::const_iterator First2 = inor.begin();  
//     vector<int>::const_iterator Second2 = inor.begin() + *pos;
//     vector<int>::const_iterator End2 = inor.end(); 
//     // leftinor.assign(inor.begin(), pos);
//     // rightinor.assign(pos+1, inor.end());
//     leftinor.assign(First2, Second2);
//     rightinor.assign(Second2+1, End2);

//     func(leftinor, leftpost);
//     func(rightinor, rightpost);

// }
// int main() {
//     freopen("in.in", "r", stdin);
//     int n, num;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> num;
//         post.push_back(num);
//     }
//     for(int i = 0; i < n; i++) {
//         cin >> num;
//         inor.push_back(num);
//     }
//     func(inor, post);
//     cout << endl;
//     return 0;
// }
// 中序+后续->层序
#include <iostream>
#include <algorithm>
#define maxN 30
#include <cstdio>
#include <vector>
using namespace std;
int post[maxN];
int in[maxN];
int n;
// 最多有maxN层
vector<int> v[maxN];
vector<int> res;
int height = 0;
void dfs(int postL, int postH, int inL, int inH, int floor){
    int root = post[postH - 1];
    // 将当前子树的根节点加入对应深度的向量中
    v[floor].push_back(root);
    height = max(height, floor);
    
    // 找出根节点在中序遍历中的下标，
    int rootIndexInOrder = -1;
    for(int i = inL; i < inH; i++){
        if(in[i] == root){
            rootIndexInOrder = i;
            break;
        }
    }
    
    // 计算左子树的结点数
    int leftSize = rootIndexInOrder - inL;
    
    // 如果左子树结点数 > 0，递归统计，左子树为
    //in[inL], in[inL + 1] ... in[rootIndexInOrder - 1]
    //post[postL], post[postL + 1] ... post[postL + leftSize]
    if(leftSize > 0){
        dfs(postL, postL + leftSize, inL, rootIndexInOrder, floor + 1);
    }
    
    // 如果右子树结点数 > 0，递归统计，右子树为
    //in[rootIndexInOrder + 1], in[rootIndexInOrder + 2] ... in[inH - 1]
    //post[postL + leftSize], post[postL + leftSize + 1] ... post[postH - 1]
    if(rootIndexInOrder < inH - 1){
        dfs(postL + leftSize, postH - 1, rootIndexInOrder + 1, inH, floor + 1);
    }
}
int main() {
    freopen("in.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    dfs(0, n, 0, n, 0);
    // 输出根结点
    printf("%d", v[0][0]);
    
    // 输出各层
    for(int i = 1; i <= height; i++){
        for(int j = 0; j < v[i].size(); j++){
            printf(" %d", v[i][j]);
        }
    }
    return 0;
}