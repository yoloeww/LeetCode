class Solution 
{ 

public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if(leftBorder == -2 || rightBorder == -2)
        return {-1,-1};
        if (rightBorder - leftBorder > 1) 
        return {leftBorder + 1, rightBorder - 1};
        return {-1, -1};
    }
private:
     int getRightBorder(vector<int>& nums, int target) 
     {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) 
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) 
            {
                right = middle - 1;
            } 
            else 
            { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
     int getLeftBorder(vector<int>& nums, int target) 
     {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) 
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) 
            {
                right = middle - 1;
                leftBorder = right;
            } 
            else 
            { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};
