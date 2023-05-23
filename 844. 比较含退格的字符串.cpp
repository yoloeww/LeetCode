class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
    string build(string str) {
        string ret;
        for(auto ch : str){
            if (ch != '#') {
                ret.push_back(ch);
            }
            else if(!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};
