class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n = matrix[0].size();
       int row = m - 1;
       int clo = 0;
       while (row >= 0 && clo < n) {
           int num = matrix[row][clo];
           if (num == target) return true;
           if (num > target) {
               row --;
           }
           else{
               clo ++;
           }
       }
       return false;
    }
};
