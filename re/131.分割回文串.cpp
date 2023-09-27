class Solution {
public:
vector<vector<string>> res;
vector<string> path;
    void backtrack(string s,int start) {
        if (start >= s.size()) { // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
            res.push_back(path);
            return ;
        }   
        for (int i = start; i < s.size(); i ++) {
            if (isVaild(s,start,i)) {
                string str = s.substr(start,i - start + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            backtrack(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back();
        }
      
    }
    bool isVaild(const string& s, int start, int end) {
     for (int i = start, j = end; i < j; i++, j--) {
         if (s[i] != s[j]) {
             return false;
         }
     }
     return true;
 }
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return res;
        backtrack(s,0);
        return res;
    }
};
