class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int>sum;
        sum.resize(2);
        unordered_map<int, int> freq;
        for (int num: nums) 
        {
            ++freq[num];
        }
        int end = 0;
        int i = 0;
        for (auto [num, occ]: freq) 
        {
            if (occ == 1) 
            {
                 sum[i] = num;
                 i++;
            }
        }
        return sum;
    }
};
