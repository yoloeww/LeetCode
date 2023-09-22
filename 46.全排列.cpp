class Solution {
public:
vector<vector<int>> res;
    void dfs(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(),false);
        trackback(nums,path,used);
    }
    void trackback(vector<int>& nums,vector<int>&path,vector<bool>&used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            trackback(nums, path, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return res;
        dfs(nums);
        return res;
    }
};
