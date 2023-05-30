#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    vector<int> add(vector<int> &a,vector<int> &b) {
    if (b.size() < a.size()) return add(b, a);
    vector<int> c;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ )
    {
        int s = t;
        if (i < a.size()) s += a[i];
        if (i < b.size()) s += b[i];
        c.push_back(s % 10);
        t = s / 10;
    }
    return c;
    } 
    string solve(string s, string t) {
        // write code here
        vector<int> a,b;
        for (int i = s.size() - 1; i >= 0; i --) {
            a.push_back(s[i] - '0');
        }
        for (int i = t.size() - 1; i >= 0; i --) {
            b.push_back(t[i] - '0');
        }
        vector<int> res = add(a,b);
        string ans;
        for (int i = res.size() - 1; i >= 0; i--) {
            ans += res[i] + '0';
        }
        return ans;
    }
};
