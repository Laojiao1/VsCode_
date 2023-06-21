#include <iostream>
#include <queue>

using namespace std;

// 二叉树结点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        // 将当前层的所有结点依次出队，并将它们的左右孩子结点入队
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        res.push_back(level);
    }

    return res;
}

int main() {
    // 构造一个二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);

    // 输出层序遍历结果
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
