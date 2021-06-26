class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int i = 0, n = nums.size();
        long long sum = 0LL, curr;
        bool ok = 1;
        
        while (i < n) {
            curr = nums[i];
            
            if (ok) {
                while (i < n && nums[i] >= curr) {
                    curr = nums[i++];
                }
                
                sum += curr;
                ok = 0;
            }
            else {
                while (i < n && nums[i] <= curr) {
                    curr = nums[i++];
                }
                
                sum += (curr * -1);
                ok = 1;
            }
        }
        
        if (ok == 1) sum += curr;
        
        return sum; 
    }
};
