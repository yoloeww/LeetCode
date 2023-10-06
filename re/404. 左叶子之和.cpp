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
    int sumProcess(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right== NULL) return 0;
        int leftValue = sumOfLeftLeaves(root->left);  //   左
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) 
     // 左叶子节点处理逻辑
            leftValue = root->left->val;
        int rightValue = sumOfLeftLeaves(root->right);  // 右
        int sum = leftValue + rightValue;               // 中
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumProcess(root);
    }
};
