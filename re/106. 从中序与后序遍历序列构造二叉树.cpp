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
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        // 叶子节点
        if (postorder.size() == 1) return root;

        int delimiterIndex;
        // 找到中序遍历的切割点
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex ++) {
             if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(),inorder.begin() + delimiterIndex);
        vector<int> rightInorder (inorder.begin() + delimiterIndex + 1,inorder.end());
        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);
        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 中序：左根右
        // 后序：左右根
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder,postorder);
    }
};
