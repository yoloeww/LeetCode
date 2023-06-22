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
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int> mp;
        mp[0] = 1;

        return backTrack(root,mp,targetSum,0);
    }
    int backTrack(TreeNode* root,  map<long long,int> mp,int targetSum,long long cursum) {
        if (root == nullptr) {
            return 0;
        }
        
        cursum += root -> val;
        int res = mp[targetSum - cursum];
        mp[cursum] ++;

        res += backTrack(root -> left,mp,targetSum,cursum);
        res += backTrack(root -> right,mp,targetSum,cursum);

        mp[cursum --];
        return res;
    }
};
