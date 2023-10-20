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
    TreeNode* traversal(vector<int>& inorder,int inorderBegin,int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
        if (preorderBegin == preorderEnd) return nullptr;
        int rootValue = preorder[inorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin;delimiterIndex < inorderEnd; delimiterIndex ++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || preorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};
