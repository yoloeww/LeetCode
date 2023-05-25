/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        if(root == nullptr)
            return true;
        queue<TreeNode*> q;
        bool lef = false;
        TreeNode* l = nullptr;
        TreeNode* r = nullptr;
        q.push(root);
        while (q.size()) {
            TreeNode* cur = q.front();
            q.pop();
            l = cur -> left;
            r = cur -> right;
            if((lef && (l != nullptr || r != nullptr)) || (l == nullptr && r != nullptr)) {
                return false;
            }
            if (l != nullptr)
                q.push(l);
            if (r != nullptr)
                q.push(r);
            else {
                lef = true;
            }
        }
        return true;
    }
};
