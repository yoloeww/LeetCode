#include <unordered_map>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            hash[numbers[i]]++;
        }
        for (int i = 0; i < numbers.size(); i++) {
            if (hash[numbers[i]] > 1) {
                return numbers[i];
            }
        }
        return -1;
    }
};
