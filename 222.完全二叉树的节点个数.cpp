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
    int getNodeNum(TreeNode* cur) {
        if(cur == nullptr) return 0;
    int leftNum = getNodeNum(cur -> left);
    int rightNum = getNodeNum(cur -> right);
    int treeNum = leftNum + rightNum + 1;
    return treeNum;
    }
    int countNodes(TreeNode* root) {
      return getNodeNum(root);
    }
};
