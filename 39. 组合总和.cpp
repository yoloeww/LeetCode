class Solution {
public:
vector<vector<int>> res;
vector<int> path;
	void dfs(vector<int>& candidates,int target,int start,int sum) {
		if (sum == target) {
			res.push_back(path);
			return ;
		}
		for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++) {
			path.push_back(candidates[i]);
			dfs(candidates,target,i,sum + candidates[i]);
			path.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	if (candidates.size() == 0) return res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0);
       	return res;
    }
};
