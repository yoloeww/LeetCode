class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        s += " ";
        string temp = "";
        vector<string> res;
        for (auto ch : s) {
            if (ch == ' ') {
                if (!temp.empty()) {
                    res.push_back(temp);
                    temp.clear();
                }
            }
            else {
                temp += ch;
            }
        }
         if (res.empty())
            return 0;
        return res.back().size();
    }
};
