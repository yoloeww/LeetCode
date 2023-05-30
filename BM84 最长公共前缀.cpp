class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        if(!strs.size()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[0][i] != strs[j][i] || i == strs[j].size())        
                    return strs[0].substr(0,i);
                }
            }
        return strs[0];
    }
};
