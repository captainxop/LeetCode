class Solution {
private:
    bool sudokuHelper(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    if(!isValid(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        int cnt = 0;
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) cnt++;
            if(board[i][col] == ch) cnt++;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) cnt++;
        }
        
        return cnt == 3;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return sudokuHelper(board);
    }
};