
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 0;
        int pre = 0;
        int res = 0;
        vector<int>dp (s.size() + 1,0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
                }
            }
            res = max(dp[i],res);
        }
        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 0;
        int left = 0, right = 0, maxlength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                left ++;
            else {
                right ++;
            }
            if (left == right) {
                maxlength = max(maxlength,2 * right);
            }
            else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
             if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
