class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size(), dp[n + 1], ans = INT_MIN;
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = max(nums[i - 1] + dp[i - 1], nums[i - 1]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
