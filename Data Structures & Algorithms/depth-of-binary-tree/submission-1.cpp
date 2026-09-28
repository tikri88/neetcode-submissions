/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getMaxDepth(TreeNode* ptr)
    {
        if(ptr == nullptr)
            return 0;
        int d = 1 + std::max(getMaxDepth(ptr->left), getMaxDepth(ptr->right));
        return d;
    }
    int maxDepth(TreeNode* root) {
        int d = getMaxDepth(root);
        return d;
    }
};
