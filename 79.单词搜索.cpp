class Solution {
public: 
int m, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;
    bool solveHelper(vector<vector<char>>& board, int x, int y, string& word, int idx)  {
        if (idx == word.size() - 1 && board[x][y] == word[idx]) {
            return true;
        }
        else if(board[x][y]!=word[idx]){
            return false;
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
             int nx=x+dx[i], ny=y+dy[i];
             if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]){
                 if(solveHelper(board, nx, ny, word, idx+1)){
                    return true;
                }
             }
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size(), n=board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(solveHelper(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
