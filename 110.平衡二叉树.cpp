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
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node -> right);
        if (rightHeight == -1) return -1;
        int result;
        if(abs(leftHeight - rightHeight) > 1) {
            result = -1;
        }
        else {
            result = 1 + max(leftHeight,rightHeight);
        }
        return result;

    }
    bool isBalanced(TreeNode* root) {
     return getHeight(root) == -1 ? false : true;
    }
}
