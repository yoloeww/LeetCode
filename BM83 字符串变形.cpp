#include <algorithm>
#include <cctype>
#include <iterator>
class Solution {
public:
    string trans(string s, int n) {
        // write code here
        if (n == 0)
            return s;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                res += tolower(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
                res += toupper(s[i]);
            else
                res += s[i];
        }
        reverse(res.begin(),res.end());
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && res[j] != ' ') {
                j ++;
            }
            reverse(res.begin() + i, res.begin() + j);
            i = j;
        }
        return res;
    }
};
