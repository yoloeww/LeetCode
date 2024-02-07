class Solution {
public:
vector<string> res
vector<int> vis;
    void dfs(int x,int size,string &s,string &temp) {
        if (x == size) {
            res.push_back(temp);
            return ;
        }
        for (int i = 0; i < size; i++) {
            if(vis[i] || (i > 0 && !vis[i - 1] && s[i - 1] == s[i])) continue;
            vis[i] = true;
            temp.push_back(s[i]);
            dfs(x + 1,size,s,temp);
            temp.pop_back();
            vis[i] = false;
        }
        
    }
    vector<string> permutation(string s) {
        int size = s.size();
        vis.resize(size);
        sort(s.begin(),s.end());
        string path;
        dfs(0,size,s,path);
        return res;
    }
};
