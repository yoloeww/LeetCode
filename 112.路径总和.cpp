class solution {
public:  
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == null) return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return haspathsum(root->left, sum - root->val) || haspathsum(root->right, sum - root->val);
    }
};
