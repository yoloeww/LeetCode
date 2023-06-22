class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        int n = nums.size();

        for (auto item : nums) {
            mp[item] ++;
        }
        for (int i = 1; i <= n; i ++) {
            if (mp[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }

};
