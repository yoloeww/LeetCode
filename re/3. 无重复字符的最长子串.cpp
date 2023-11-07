class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> windows;
        int left = 0,right = 0;
        int res = 0;
        int n = s.size();
        while (right < n) {
            char c = s[right];
            right ++;
            windows[c] ++;
            while (windows[c] > 1) {
                char d = s[left];
                left ++;
                windows[d] --;
            }
            res = max(res,right - left);
        }
        return res;
    }
};
