/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool process(TreeNode* A,TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr || A -> val != B -> val)
            return false;
        return process(A -> left,B -> left) && process(A -> right,B -> right);
        
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;
        return process(A,B) || isSubStructure(A -> left,B) || isSubStructure(A -> right,B);
    }
};
