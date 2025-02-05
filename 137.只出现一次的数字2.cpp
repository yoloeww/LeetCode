class Solution：
{
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for (int num: nums) 
        {
            ++freq[num];
        }
        int end = 0;
        for (auto [num, occ]: freq) 
        {
            if (occ == 1) 
            {
                end = num;
                break;
            }
        }
        return end;
    }
 };
