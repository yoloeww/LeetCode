class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 1. dp[i][j] 表示，nums1以i - 1结尾，nums2以j - 1结尾的最长重复子数组的长度
        // 2. 方程： dp[i][j] = dp[i - 1][j - 1] + 1;
        // 3. 初始化 所以dp[i][0] 和dp[0][j]初始化为0。
        // 4. 顺序 外层for循环遍历A，内层for循环遍历B。
        // 5. 打印
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
