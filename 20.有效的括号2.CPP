class Solution {
public：
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(')
                st.push(')');
            else if (ch == '[')
                st.push(']');
            else if (ch == '{')
                st.push('}');
            else if (st.empty() || ch != st.top()) {
                return false;
            }
            else 
                st.pop();
        }
        return st.empty();
    }
};
