class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int dp[101][101];
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;
        }
        else {
            dp[0][0] = 0;
        }
        
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[0][i] == 0) {
                dp[0][i] = dp[0][i-1];
            }
            else {
                dp[0][i] = 0;
            }
        }
        
        for(int i = 1; i < n; i++) {
            if(obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
            else {
                dp[i][0] = 0;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};
