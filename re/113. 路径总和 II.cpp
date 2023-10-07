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
vector<vector<int>> res;
vector<int> path;
    void tra(TreeNode* root,int count) {
        if (!root -> left && !root ->right && count == 0) {
            res.push_back(path);
            return;
        }
        if (!root -> left && !root ->right)
            return;
        if (root -> left) {
            path.push_back(root -> left -> val);
            count -= root -> left -> val;
            tra(root -> left,count);
            count += root -> left -> val;
            path.pop_back();
        }
         if (root -> right) {
            path.push_back(root -> right -> val);
            count -= root -> right -> val;
            tra(root -> right,count);
            count += root -> right -> val;       
            path.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return res;
        path.push_back(root->val);
        tra(root,targetSum - root -> val);
        
        return res;
    }
};
