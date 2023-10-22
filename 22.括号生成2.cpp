class Solution {
public:
vector<string> res;
string path;
	void process(int open,int close,int n) {
		if (path.size() == n * 2) {
			res.push_back(path);
			return ;
		}
		if (open < n) {
			path.push_back('(');
            process(open + 1,close,n);
            path.pop_back();
		}
		if (close < open) {
			path.push_back(')');
            process(open,close + 1,n);
            path.pop_back();
		}
	}
    vector<string> generateParenthesis(int n) {
		if (n == 0) return res;
		if (n == 1) return {"()"};
		process(0,0,n);
		return res;
    }
};
