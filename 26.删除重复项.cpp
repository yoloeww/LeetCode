class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
         if(nums.size() == 0)
         return 0;
         int fast = 1,slow = 1; //定义快慢指针 快指针遍历 慢指针下标
         while(fast < nums.size())
         {
             if(nums[fast] != nums[fast - 1])
             {
                  nums[slow] = nums[fast];
                  slow++;
             }
             fast++;
         }
         return slow;
    }
};
