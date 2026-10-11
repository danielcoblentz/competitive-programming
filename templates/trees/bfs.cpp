#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
#define vvi vector<vector<int>>

class TreeNode {
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val_ = val;
        }
};

vvi bfs(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    vvi res;

    q.push(root);

    while (q.size()) {
        int length = q.size();
        vector<int> lvl;
        for (int i = 0; i < length; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            lvl.push_back(node->val_);
        }

        res.push_back(lvl);
    }

    return res;
}
