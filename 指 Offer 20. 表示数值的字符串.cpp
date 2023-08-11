class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(),l = 0,r = n - 1;
        while (l < n && s[l] == ' ') l ++;
        while (r >= 0 && s[r] == ' ') r--;
        if (l > r) return false;
        s = s.substr(l,r - l + 1);
        for (char &c : s) {
            if (c == 'e') c = 'E';
        }
        n = s.size();
        int index = 0;
        while (index < n && s[index] != 'E') index ++;
        if (index == n)
            return check(s,true);
        else {
            return check(s.substr(0,index),true) && check(s.substr(index + 1),false);
        }
    }
    bool check(string s,bool isDecimal) {
        if (s == "." || s == "") return false;
        int n = s.size();
        for (int i = 0,cnt = 0; i < n; i++) {
            char c =s[i];
            if (c == '+' || c == '-') {
                
            }
        }
    }
};
