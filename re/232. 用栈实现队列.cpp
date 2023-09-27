class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<char> t;
        for (auto ch : s) {
            if (ch == '(') { // 
                t.push(')');
            }
            else if (ch == '[') {
                t.push(']');
            }
            else if (ch == '{') {
                t.push('}');
            }
            else if (t.empty() || ch != t.top()) { 
                // 第一种情况：已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false
                // 第二种情况：遍历字符串匹配的过程中，发现栈里没有要匹配的字符。所以return false
                // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号return false
                return false;
            }
            else {
                t.pop();
            }
        }
       return t.empty();
    }
};
