class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int l = 0,r = matrix[0].size() - 1; // 左右
        int t = 0,b = matrix.size() - 1; // 上下
        int x = 0;
        res.resize((r + 1) * (b + 1));

        while (1) {
            for (int i = l; i <= r; i ++) res[x++] = matrix[t][i];
            if(++t > b) break;
            for (int i = t; i <= b; i++) res[x++] = matrix[i][r];
            if(l > --r) break;
            for(int i = r; i >= l; i--) res[x++] = matrix[b][i]; // right to left.if(t > --b) break;
             if(t > --b) break;
            for(int i = b; i >= t; i--) res[x++] = matrix[i][l]; // bottom to top.
            if(++l > r) break;
        }
        return res;
    } 
};
