class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    
        int left = 0, right = nums.size() - 1;
        int middle;
        while(left <= right)
        {
            middle = (left + right)/2;
            if(target > nums[middle])
            {
                left = middle + 1;
            }
            else 
            {
                right = middle - 1;
            }
        }
        return left;
    }
};
