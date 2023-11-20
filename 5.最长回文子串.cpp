#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        string origin = s;
        string reverse = string(s.rbegin(), s.rend());
        int length = s.length();
        vector<vector<int>> arr(length, vector<int>(length));
        int maxLen = 0;
        int maxEnd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (origin[i] == reverse[j]) {
                    if (i == 0 || j == 0) {
                        arr[i][j] = 1;
                    } else {
                        arr[i][j] = arr[i - 1][j - 1] + 1;
                    }
                }
                if (arr[i][j] > maxLen) {
                    int beforeRev = length - 1 - j; // 所以 j 指向的红色的 a 倒置前的下标是 beforeRev = length-1-j=4-1-2=1，对应的是字符串首位的下标
                    if (beforeRev + arr[i][j] - 1 == i) { 
              // 我们还需要加上字符串的长度才是末尾字符的下标，因为 arr\[i][j] 保存的就是当前子串的长度，也就是图中的数字 3。此时再和它与 i 比较，如果相等，则说明它是我们要找的回文串。
                        maxLen = arr[i][j];  
                        maxEnd = i;
                    }
                }
            }
        }
        return s.substr(maxEnd - maxLen + 1, maxLen);
    }
};
