#include <stack>
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;

        if(s.size() % 2)
            return false;
        for (auto x : s) {
            if (x == '(')
                st.push(')');
            else if (x == '[')
                st.push(']');
            else if (x == '{')
                st.push('}');
            else if (st.empty() || st.top() != x) // 栈空或者括号栈顶字符与当前字符不匹配，则序列为不合法序列
                return false;
            else 
                st.pop();
        }
        return st.empty();
    }
};
