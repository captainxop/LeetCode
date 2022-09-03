class Solution {
private:
    vector<vector<string>> ans;
    
    void nQueensHelper(vector<string> &board, int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(isPossible(board, row, col, n)) {
                board[row][col] = 'Q';
                nQueensHelper(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool isPossible(vector<string> &board, int row, int col, int n) {
        int r = row, c = col;
        
        while(row >= 0) { // check above
            if(board[row][col] == 'Q') return false;
            row--;
        }
        
        row = r;
        while(row >= 0 && col >= 0) { // check upper left diagonal
            if(board[row][col] == 'Q') return false;
            row--, col--;
        }
        
        row = r, col = c;
        while(row >= 0 && col < n) { // check upper right diagonal
            if(board[row][col] == 'Q') return false;
            row--, col++;
        }
        
        return true;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i = 0; i < n; i++) board.push_back(string(n, '.'));
        nQueensHelper(board, 0, n);
        return ans;
    }
};