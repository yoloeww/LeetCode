// 对于匹配的过程，暴力的方法是 O(n) 遍历数组去看是否存在这个数，但其实更高效的方法是用一个哈希表存储数组中的数，这样查看一个数是否存在即能优化至 O(1) 的时间复杂度
// 那么怎么判断是否跳过呢？
由于我们要枚举的数 x 一定是在数组中不存在前驱数x−1的，不然按照上面的分析我们会从 x−1 开始尝试匹配，因此我们每次在哈希表中检查是否存在 x−1即能判断是否需要跳过了。
class Solution {   

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        if (nums.size() == 0) return 0;
        for (const int& num : nums) {
            mp.insert(num);
        }
        int longest = 0;
        for (auto num : mp) {
            if (!mp.count(num - 1)) {
                int curNum = num;
                int curStreak = 1;
                while (mp.count(curNum + 1)) {
                    curNum += 1;
                    curStreak += 1;
                }
                longest = max(longest,curStreak);
            }
            
        }
        return longest;
    }
};
