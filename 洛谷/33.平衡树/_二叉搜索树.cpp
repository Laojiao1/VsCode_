// https://www.luogu.com.cn/problem/P5076
// https://www.cnblogs.com/do-while-true/p/13566274.html
// 学习平衡树前，要理解并掌握二叉搜索树
// 二叉搜索树的代码没必要背，不如多学几个平衡树
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
struct Tree {
	int val; // 权值 
 	int ls; // 左儿子的下标 
	int rs; // 右儿子的下标 
	int cnt; //当前权值出现了几次 
	int size_; // 子树大小和自己大小的和 
} tree[500010];
int cont, n, opt, xx;

inline void add(int x, int val) { // x:当前节点的下标，v：要插入的值 
	tree[x].size_++;
    // 如果查到这个节点，说明这个节点的子树里面肯定是有v的，所以siz++
	if(tree[x].val == val) {
        // 如果恰好有重复的数，就把cnt++，退出即可，因为我们要满足第四条性质
		tree[x].cnt++;
		return;
	}
	if(tree[x].val > val) { // 如果tree[x].val > val，说明val是在左子树里
		if(tree[x].ls != 0) { // 如果左子树不为空，继续向左找
			add(tree[x].ls, val);
		} else { // 如果不是，那么val 就是 x 结点的权值
			cont++; // cont是目前BST里有几个结点
			tree[cont].val = val;
			tree[cont].cnt = tree[cont].size_ = 1;
			tree[x].ls = cont;
		}
	} else { // 右子树同理
		if(tree[x].rs != 0) {
			add(tree[x].rs, val);
		} else {
			cont++;
            tree[cont].val = val;
			tree[cont].cnt = tree[cont].size_ = 1;
			tree[x].rs = cont; 
		}
	}
}

int querypre(int x, int val, int ans) { // x: 当前节点的下标，val：要找的前驱节点的值，ans：目前找到的比val小的最大值 
	if(tree[x].val >= val) {
        // 如果当前结点的权值大了，说明要去左子树查找
		if(tree[x].ls == 0) {
			return ans; // 如果左子树为空，直接返回找到的ans
		} else { // 不为空的话继续往左找
			return querypre(tree[x].ls, val, ans);
		}
	} else {
        // 反之向右子树查找
		if(tree[x].rs == 0) {
			return tree[x].val; // 如果没有右孩子，就返回tree[x].val，因为走到这一步时，我们后找到的一定比先找到的大
		} 
        // 如果有右孩子，我们还要找这个节点的右子树，因为万一右子树有比当前节点还大并且小于要找的val的话，ans需要更新
		return querypre(tree[x].rs, val, tree[x].val);
	}
}

int querynext(int x, int val, int ans) { // 找后继与找前驱同理
	if(tree[x].val <= val) {
		if(tree[x].rs == 0) {
			return ans;
		} else {
			return querynext(tree[x].rs, val, ans);
		}
	} else {
		if(tree[x].ls == 0) {
			return tree[x].val;
		} 
		return querynext(tree[x].ls, val, tree[x].val);
	}
}

int queryval(int x, int val) { // 按值找排名
	if(x == 0) return 0; // x == 0 没有排名
	if(val == tree[x].val) { // 找到了，就返回左子树的大小
		return tree[tree[x].ls].size_;
	}
	if(val < tree[x].val) { // 如果值大了，就向左找
		return queryval(tree[x].ls, val);
	}
	return queryval(tree[x].rs, val) + tree[tree[x].ls].size_ + tree[x].cnt;
    // 反之，去它的右子树找val，同时加上左子树的大小和这个节点的值出现次数 
	// 因为这个节点的值小于val，这个节点的左子树的各个节点的值一定也小于val 
    // 注:这里最终返回的是排名-1，也就是比val小的数的个数，在输出的时候记得+1
}

// 因为性质1和性质2，我们发现排名为 n 的数在BST上是第 n 靠左的数。
// 或者说排名为 n 的数的节点在BST中，它的左子树的 size 与它的各个祖先的左子树的 size 相加恰好 = n (这里相加是要减去重复部分)。
int queryrk(int x, int rk) { // 按排名找值，rk：要找的排名
	if(x == 0) return INF;
	if(tree[tree[x].ls].size_ >= rk) { // 如果左子树的大小大于rk，说明答案在左子树中
		return queryrk(tree[x].ls, rk);
	}
	if(tree[tree[x].ls].size_ + tree[x].cnt >= rk) { // 如果左子树大小加上当前的数的多少恰好>=k，说明我们找到答案了，返回权值
		return tree[x].val; 
	}
    // 否则就查右子树，同时减去当前节点的次数与左子树的大小 
	return queryrk(tree[x].rs, rk - tree[tree[x].ls].size_ - tree[x].cnt);
}

int main() {
	cin >> n;
	while(n--) {
		cin >> opt >> xx;
		if(opt == 1) cout << queryval(1, xx) + 1 << endl;
		else if(opt == 2) cout << queryrk(1, xx) << endl;
		else if(opt == 3) cout << querypre(1, xx, -INF) << endl;
		else if(opt == 4) cout << querynext(1, xx, INF) << endl;
		else {
			if(cont == 0) {
				cont++;
				tree[cont].size_ = tree[cont].cnt = 1;
				tree[cont].val = xx;
			} else {
				add(1, xx);
			}
		}
	}
	return 0;
}
