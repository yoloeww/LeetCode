class Solution:
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return {0,0};
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                return {it -> second,i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};

    }
};
