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
    unordered_map<int, int> index;
    TreeNode* myBuildTree(const vector<int> & preorder,const vector<int> &inorder,int preorder_left,int preorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int preorder_root = preorder_left;

          m
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder,inorder,n - 1,0,n - 1);
    }
};
