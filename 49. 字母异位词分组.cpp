class Solution { 
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 遍历每个字符串，对于每个字符串，得到该字符串所在的一组字母异位词的标志，将当前字符串加入该组字母异位词的列表中。
        // 遍历全部字符串之后，哈希表中的每个键值对即为一组字母异位词。

        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        if (strs.size() == 0) return res;
        for (auto str : strs) {
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for (auto it = mp.begin(); it != mp.end(); it ++) {
            res.emplace_back(it -> second);
        }
        return res;
    }
};
