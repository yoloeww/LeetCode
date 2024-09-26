class Solution {
public:   
   vector<int>twoSum(vector<int>& nums, int target) 
        int i = 0,j = 1;
        int maxArea = nums.size()-1;
        while (nums[i] + nums[j] = target)
              if(j == maxArea)
              {
                i++;，
                j = i；
              }
              j++; 
        }
       return {i, j};
    }
};
