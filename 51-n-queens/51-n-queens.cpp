class Solution {
private:
    vector<vector<string>> ans;
    
    void nQueensHelper(vector<string> &board, vector<int> &up, vector<int> &upLeftDiagonal, vector<int> &upRightDiagonal, int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(up[col] == 0 && upLeftDiagonal[n - 1 - (col - row)] == 0 && upRightDiagonal[row + col] == 0) {
                board[row][col] = 'Q';
                up[col] = 1;
                upLeftDiagonal[n - 1 - (col - row)] = 1;
                upRightDiagonal[row + col] = 1;
                
                nQueensHelper(board, up, upLeftDiagonal, upRightDiagonal, row + 1, n);
                
                board[row][col] = '.';
                up[col] = 0;
                upLeftDiagonal[n - 1 - (col - row)] = 0;
                upRightDiagonal[row + col] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> up(n, 0), upLeftDiagonal(2 * n - 1, 0), upRightDiagonal(2 * n - 1, 0);
        nQueensHelper(board, up, upLeftDiagonal, upRightDiagonal, 0, n);
        return ans;
    }
};