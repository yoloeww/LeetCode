class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int curSum = 0;
        int minLength = 0;

        while (right < nums.size()) {
            curSum += nums[right];
            while (curSum >= target) {
                if (right - left + 1 < minLength || minLength == 0) {
                    minLength = right - left + 1;
                }
                curSum = curSum - nums[left];
                left ++;
            }
            right ++;
        }
        return minLength;
    }
