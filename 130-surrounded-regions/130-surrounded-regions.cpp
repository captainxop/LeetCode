class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void bfs(vector<vector<char>> &board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] || board[ni][nj] != 'O') continue;
                q.push({ni, nj});
                visited[ni][nj] = 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        bfs(board);
    }
};