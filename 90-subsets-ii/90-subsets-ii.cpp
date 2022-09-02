class Solution {
private:
    vector<vector<int>> ans;
    
    void helper(vector<int> &nums, int idx, int n, vector<int> &temp) {
        ans.push_back(temp);
        
        for(int i = idx; i < n; i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            
            temp.push_back(nums[i]);
            helper(nums, i + 1, n, temp);
            temp.pop_back();
        }        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums, 0, n, temp);
        return ans;
    }
};