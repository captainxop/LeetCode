class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
                
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long t = (long long)target - (nums[i] + 0LL + nums[j]);
                
                int l = j + 1, r = n - 1;
                while(l < r) {
                    if(nums[l] + 0LL + nums[r] == t) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l++, r--;
                    }
                    else if(nums[l] + 0LL + nums[r] < t) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
                
                while(j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        
        return ans;
    }
};