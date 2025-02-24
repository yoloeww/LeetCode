
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
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        pre(root,res);
        int n = res.size();
        for (int i = 1; i < n; i++) {
             TreeNode *prev = res.at(i - 1),*cur = res.at(i);
             prev -> left = nullptr;
             prev -> right = cur;
        }
    }
    void pre(TreeNode* root,vector<TreeNode* >& res) {
        if (root) {
            res.push_back(root);
            pre(root -> left,res);
            pre(root -> right,res);
        }
    }
};
