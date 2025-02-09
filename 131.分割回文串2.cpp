class Solution {   
public: 
vector<vector<string>> res;
string path;
	void process(string &s,int index) {
		if (index >=
			s.size()) {
			res.push_back(path);
			return ;
		}
		for (int i = index; i < s.size(); i++) {
			if (isVaild(s,index,i) {
				string str = s.substr(index,i - index + 1);
				path.push_back(str);
			}
			else {
				continue;
			}
			 process(s,i + 1);
            path.pop_back();
		}
		
	}
	bool isVaild(string &s,int open,int close) {
		for (int i = open,j = close; i < j; i ++,j --） {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}
    vector<vector<string>> partition(string s) {
		if (s.size() == 1) return res;
		process(s,0);
		return res;
    }
};
