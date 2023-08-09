class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string temp = "";
        vector<string> res;
        for (auto ch : s) {
            if (ch == ' ') {
                res.push_back(temp);
                temp.clear();
            }
            else {
                temp += ch;
            }
        }
        s.clear();
        for (auto t : res) {
            reverse(t.begin(),t.end());
            s += t + ' ';
        }
        s.pop_back();
        return s;
    }
};
