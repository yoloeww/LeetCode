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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int &prei,int inbegin,int inend) {
        if(inbegin > inend)
            return nullptr;
        int rooti = inbegin;
        TreeNode* root = new TreeNode(postorder[prei]);
        
        while (rooti <= inend) {
            if (inorder[rooti] == postorder[prei]) {
                break;
            }
            ++ rooti;
        }
        prei --;
        root -> right = _buildTree(inorder,postorder,prei,rooti + 1,inend);
        root -> left = _buildTree(inorder,postorder,prei,inbegin,rooti - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p = inorder.size() - 1;
        return _buildTree(inorder,postorder,p,0,inorder.size() - 1);
    }
};
