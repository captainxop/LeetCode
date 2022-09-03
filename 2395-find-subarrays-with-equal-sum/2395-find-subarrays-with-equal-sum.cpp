class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            int x = nums[i] + nums[i + 1];
            
            for(int j = i + 1; j < n - 1; j++) {
                int y = nums[j] + nums[j + 1];
                
                if(x == y) return true;
            }
        }
        
        return false;
    }
};