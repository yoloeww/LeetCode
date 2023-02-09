class Solution {
public:
    using pbi = pair<bool, int>;
    void dfs(int& n, vector<pbi>& used, int row){
        //结束条件：
        if(path.size() == n){
            vret.push_back(path);
            return;
        }
        //开辟并初始化used2：
        vector<bool> used2(n, 0);
        for(int i=0; i<n; i++){
            if(used[i].first == true){
                used2[i] = true;
                int rdif = row-used[i].second;
                if(i-rdif >= 0) used2[i-rdif] = true;
                if(i+rdif < n) used2[i+rdif] = true;
            }
        }
        if(used2 == vector<bool>(n,true)) return;    //无坑位可选

        for(int i=0; i<n; i++){
            if(used2[i] == false){
                string st(n, '.');  st[i] = 'Q';
                path.push_back(st);
                used[i] = {true, row};
                dfs(n, used, row+1);
                path.pop_back();
                used[i] = {false, 0};
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<pbi> used(n);    //某列是否使用，以及使用该列的行   
        dfs(n, used, 0);
        return vret;
    }
    vector<vector<string>> vret;
    vector<string> path;
};
