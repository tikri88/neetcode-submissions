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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Do level order traversal of both tree and compare each node value
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(q1.size() && q2.size())
        {
            TreeNode *n1 = q1.front();
            TreeNode *n2 = q2.front();
            if(n1 != nullptr && n2 != nullptr && n1->val != n2->val)
                return false;
            if((n1 == nullptr && n2 != nullptr) || (n2==nullptr && n1 != nullptr))
                return false;
            if(n1 != nullptr)
            {
                q1.push(n1->left);
                q1.push(n1->right);
            }
            if(n2 != nullptr)
            {
                q2.push(n2->left);
                q2.push(n2->right);

            }
            q1.pop();
            q2.pop();
        }
        if(q1.size() || q2.size())
            return false;
        return true;
    }
};
