class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // 1. dp[i]的定义，以i结尾的最长连续递增子序列长度
        // 2. 方程  if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
        // 3. 初始  dp[0] = 1; 
        // 4. 顺序  从左到右
        // 5. 打印 
        if (nums.size() == 0) return 0;
        int result = 1;
        vector<int> dp(nums.size() ,1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // 连续记录
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;

    }
};
