class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        sort(nums.begin(),nums.end());
        if (nums[0] > 0) return res; 
        for (int k = 0; k < nums.size() - 2; k ++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1,j = nums.size() - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0) {
                    while (i < j && nums[i] == nums[++i]) ;
                }
                else if(sum > 0) {
                    while (i < j && nums[j] == nums[--j]) ;
                }
                else {
                    res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[++i]) ;
                    while (i < j && nums[j] == nums[--j]) ;
                }
            }
        }
        return res;
    }
};
