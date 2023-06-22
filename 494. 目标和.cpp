class Solution {
public:
int cnt = 0;
    void backTrack(vector<int> & nums,int target,int index,int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                cnt ++;
            }
        }
        else {
        backTrack(nums, target, index + 1, sum - nums[index]);
        backTrack(nums, target, index + 1, sum + nums[index]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backTrack(nums,target,0,0);
        return cnt;
    }
};
