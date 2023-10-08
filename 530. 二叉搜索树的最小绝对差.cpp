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
int result = INT_MAX;
TreeNode* pre = NULL;
    void isBST(TreeNode* root) {
        if (root == nullptr) return;
        isBST(root -> left);
        if (pre != nullptr) {
            result = min(result,root -> val - pre -> val);
        }
        pre = root;
        isBST(root -> right);
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return false;
        isBST(root);
        return result;
    }
};
