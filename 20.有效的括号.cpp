class Solution{
public:
    bool isValid(string s) {
      if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack <char> use;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') 
            use.push(')');
            else if (s[i] == '{')
            use.push('}');
            else if (s[i] == '[') 
            use.push(']');
            else if (use.empty() || use.top() != s[i])
            return false;
            else
            use.pop();
        }
        return use.empty();
    }
};
