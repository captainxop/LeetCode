class Solution {
public:  
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = 0, n = nums.size(), z = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(nums[i] == 0) {
                z++;
            }
        }
        
        if(S > sum || ((S + sum) % 2 != 0)) {
            return 0;
        }
        
        int s = (sum + S) / 2;
        
        int dp[n+1][s+1]; 
        
        for(int j = 0; j <= s; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= s; j++) {
                if(nums[i-1] == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (pow(2, z) * dp[n][s]);
    }
};
