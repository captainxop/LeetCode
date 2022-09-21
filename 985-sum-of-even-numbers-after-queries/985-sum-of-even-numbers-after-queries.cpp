class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        
        for(int i = 0; i < (int)nums.size(); i++) {
            if(nums[i] % 2 == 0) sum += nums[i];
        }
        
        for(int i = 0; i < (int)queries.size(); i++) {
            int val = queries[i][0], idx = queries[i][1];
            sum -= (abs(nums[idx]) % 2 == 0 ? nums[idx] : 0);
            nums[idx] += val;
            sum += (abs(nums[idx]) % 2 == 0 ? nums[idx] : 0);
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};