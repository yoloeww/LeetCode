class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s1(s.rbegin(),s.rend());
        if (s == s1) {
            return true;
        }
        else {
            return false;
        }
    }
};
