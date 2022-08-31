class Solution {
private:
    vector<vector<int>> ans;
    
    void combinationSum2Helper(vector<int> &candidates, int idx, int target, vector<int> &temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            if(candidates[i] > target) return;
            if(i > 0 && candidates[i] == candidates[i - 1] && i > idx) continue; // duplicate combinations
            temp.push_back(candidates[i]);
            combinationSum2Helper(candidates, i + 1, target - candidates[i], temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        combinationSum2Helper(candidates, 0, target, temp);
        return ans;
    }
};