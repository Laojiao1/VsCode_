// 本篇是以递归的方式实现
// 以先序遍历输入(以#结束)要存储的元素
// 输入：
// AB#CD##E##F#GH###
// 	    A
//    /   \
//   B     F
//    \     \
//     C     G
//    / \   /
//   D   E H
// 输出：
// 先序遍历输出: ABCDEFGH
// 中序遍历输出: BDCEAFHG
// 后序遍历输出：DECBHGFA
// 该树的深度为: 4
// 该树的节点个数为: 8
// 该树的叶子个数为: 3
#include <iostream>
using namespace std;
typedef char ElemType; // 数据类型
typedef struct BiNode* BiTree;
struct BiNode {//节点的创建
	ElemType data;
	BiNode *lchild;
    BiNode *rchild;
};

void PreOrderTraverse(BiTree T) {//先序遍历
	if (T) {
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}


void InOrderTraverse(BiTree T) {//中序遍历
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T) {//后序遍历
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
}


void CreateBiTree(BiTree &T) {//创建二叉树
	char ch;
	cin >> ch;
	if (ch == '#') { // 以#为空结点
		T = NULL;
	} else {
		T = new BiNode;
		T->data = ch;
		CreateBiTree(T->lchild); // 递归创建左右儿子
		CreateBiTree(T->rchild);
	}
}

void Copy(BiTree T, BiTree &NewT) {//复制出一个新的二叉树
	if (T == NULL) {
		NewT = NULL;
		return ;
	} else {
		NewT = new BiNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

int Depth(BiTree T) { //求深度
	if (T == NULL) {
		return 0;
	} else {
		int ld = Depth(T->lchild);
		int rd = Depth(T->rchild);
		return (ld > rd ? ld : rd) + 1;
	}
}


int NodeCount(BiTree T) {//求节点的个数
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int LeafCount(BiTree T) {//求叶子的个数
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int main() {
	BiTree T;//创建一颗二叉树
	cout << "Iterates through the input in order (ending with #) to store the elements: " << endl;
	CreateBiTree(T);
	cout << "preorder traversal : "; // 先序遍历
	PreOrderTraverse(T);
	cout << endl;
	cout << "Middle-order traversal: "; // 中序遍历
	InOrderTraverse(T);
	cout << endl;
	cout << "post-order traversal: " ; // 后序遍历
	PostOrderTraverse(T);
	cout << endl;
	cout << "the depth of the tree: "; // 树的深度
	cout << Depth(T) << endl;
	cout << "the number of nodes in the tree: "; // 树的节点个数
	cout << NodeCount(T) << endl;
	cout << "the number of leaves: "; // 叶子节点个数
	cout << LeafCount(T) << endl;
	system("pause");
	return 0;
}
