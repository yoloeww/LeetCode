class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 1. dp[i] 包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]
        // 2. dp[i] = max(nums[i],dp[i - 1] + nums[i]);  dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
        // nums[i]，即：从头开始计算当前连续子序列和
        // 3.  从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。
        // 4. 1 - n
        // 5. 方程
        if (nums.size() == 0) return 0;
     
        vector<int> dp(nums.size(),0);
        
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i],nums[i]);
            if (result < dp[i]) {result = dp[i];}
        }
        return result;
    } 
};
