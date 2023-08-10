class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return {nums[i],nums[j]};
            }
            else if (sum < target) i ++;
            else j --;
        }
        return {};
    }
};
