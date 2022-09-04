class Solution {
private:
    bool sudokuHelper(vector<vector<char>> &board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isPossible(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(sudokuHelper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isPossible(vector<vector<char>> &board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false; // check row
            if(board[i][col] == ch) return false; // check column
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false; // check square
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuHelper(board);
    }
};