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
    vector<int> res;
    unordered_map<int,int> mp;
    void process(TreeNode* root) {
        if (root == nullptr) return ;
        process(root -> left);
        mp[root -> val] ++;
        process(root -> right);
    }
    bool static cmp(const pair<int,int>& a,const pair<int,int> &b) {
        return a.second > b.second;
    }
    vector<int> findMode(TreeNode* root) {
        process(root);
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp); // 给频率排个序
        res.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
            else break;
        }
        return res;
    }
};
