class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        long long sum = 0;
        
        for(int i = 0, j = 0; j < n; j++) {
            while(i < j && (sum & nums[j]) != 0) {
                sum -= nums[i];
                i++;
            }
            
            ans = max(ans, j - i + 1);
            sum += nums[j];
        }
        
        return ans;
    }
};