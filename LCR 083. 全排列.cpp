class Solution {
public:
vector<vector<int>> res;
    void process(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(),false);
        dfs(used,path,nums);

    }
    void dfs(vector<bool>& used,vector<int> &path,vector<int>& nums) {
        if (path.size() == nums.size())
        {

            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(used,path,nums);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return res;
        sort(nums.begin(),nums.end());
        process(nums);

        return res;
    }
};
