JZ5 替换空格
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
      if (s.empty()) {
        return "";
      }
      
      int blank = 0;
      int old_size = s.size();
      
      for (const auto &it : s) {
        if (it == ' ') {
          ++blank;
        }
      } 
      int j = old_size + 2 * blank - 1;
      s.resize(old_size + 2 * blank);
      for(int i = old_size - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            s[j--] = s[i];
        }
        else {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
      }
     
    
    
      return s;
    }
};
