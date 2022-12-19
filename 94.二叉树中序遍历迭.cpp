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
    vector<int> inorderTraversal(TreeNode* root) {
   vector <int> result;
    stack<TreeNode*> st;
    if(root != nullptr) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if(node != nullptr) {
            st.pop();
            if(node -> right) st.push(node -> right);
            st.push(node);
            st.push(nullptr);
            if(node -> left) st.push(node -> left);
        }
        else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }
    return result;
    }

};
