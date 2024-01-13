class Solution {
public:
    void backtrack(vector<string> &res,string &cur,int open,int close,int n) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(res,cur,open + 1,close,n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(res,cur,open,close + 1,n);
            cur.pop_back();
        }
    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 1) {
            res.push_back("()");
            return res;
        }
       string cur;
       backtrack(res,cur,0,0,n);
       return res;
    }
};
