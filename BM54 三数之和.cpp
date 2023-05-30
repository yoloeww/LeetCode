#include <unistd.h>
#include <vector>
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;

        sort(num.begin(),num.end());

        if (num.size() < 3)
            return res;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] > 0)
                return res;
            
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int left = i + 1;

            int right = num.size() - 1;

            while (right > left) {
                if (num[i] + num[left] + num[right] > 0) right--;
                else if (num[i] + num[left] + num[right] < 0) left++;
                else {
                     res.push_back(vector<int>{num[i], num[left], num[right]});
                     while(right > left && num[right] == num[right - 1]) right --;
                     while (right > left && num[left] == num[left + 1])
left ++;
                     right --;
                     left ++;
                }
            }
        }
         return res;
    }
};
