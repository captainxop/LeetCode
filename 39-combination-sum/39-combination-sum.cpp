class Solution {
private:
    vector<vector<int>> ans;
    
    void combinationSumHelper(vector<int> &candidates, int i, int target, vector<int> &temp)
    {
        if(i == candidates.size()) {
            if(target == 0) {
                ans.push_back(temp);
                return;
            }
            return;
        }
        
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinationSumHelper(candidates, i, target - candidates[i], temp);
            temp.pop_back();
        }
        
        combinationSumHelper(candidates, i + 1, target, temp);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combinationSumHelper(candidates, 0, target, temp);
        return ans;
    }
};