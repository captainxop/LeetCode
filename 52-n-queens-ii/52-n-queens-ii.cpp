class Solution {
private:    
    int totalNQueensHelper(vector<int> &up, vector<int> &upLeftDiagonal, vector<int> &upRightDiagonal, int row, int n) {
        if(row == n) {
            return 1;
        }
                
        int cnt = 0;
        
        for(int col = 0; col < n; col++) {
            if(up[col] == 0 && upLeftDiagonal[n - 1 - (col - row)] == 0 && upRightDiagonal[row + col] == 0) {
                up[col] = 1;
                upLeftDiagonal[n - 1 - (col - row)] = 1;
                upRightDiagonal[row + col] = 1;
                
                cnt += totalNQueensHelper(up, upLeftDiagonal, upRightDiagonal, row + 1, n);
                
                up[col] = 0;
                upLeftDiagonal[n - 1 - (col - row)] = 0;
                upRightDiagonal[row + col] = 0;
            }
        }
        
        return cnt;
    }
    
public:
    int totalNQueens(int n) {
        vector<int> up(n, 0), upLeftDiagonal(2 * n - 1, 0), upRightDiagonal(2 * n - 1, 0);
        return totalNQueensHelper(up, upLeftDiagonal, upRightDiagonal, 0, n);
    }
};