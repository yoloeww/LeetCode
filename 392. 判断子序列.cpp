class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 1. dp[i][j] 表示 s 以 i - 1 结尾，t 以 j - 1 结尾， 相同子序列的长度为dp[i][j]
        // 2. if (s[i - 1] == t[j - 1])，那么dp[i][j] = dp[i - 1][j - 1] + 1;，因为找到了一个相同的字符，相同子序列长度自然要在dp[i-1][j-1]的基础上加1
        // if (s[i - 1] != t[j - 1])，此时相当于t要删除元素，t如果把当前元素t[j - 1]删除，那么dp[i][j] 的数值就是 看s[i - 1]与 t[j - 2]的比较结果了，即：dp[i][j] = dp[i][j - 1];
        // 3. 初始化
        // 4. 同理从递推公式可以看出dp[i][j]都是依赖于dp[i - 1][j - 1] 和 dp[i][j - 1]，那么遍历顺序也应该是从上到下，从左到右
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
         for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
       if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};
