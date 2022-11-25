class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
          int slow = 0, fast = 0;
          for(slow = 0; slow < nums.size(); slow++)
          {
                 if(nums[slow] != val)
                 {
                      nums[fast] = nums[slow];
                      fast++;
                 }
          }
          return fast;
    }
};
