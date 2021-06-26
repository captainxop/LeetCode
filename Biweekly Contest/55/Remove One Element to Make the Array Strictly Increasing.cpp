class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            vector<int> a;
            
            for(int j = 0; j < n; j++) {
                if(i != j) a.push_back(nums[j]);
            }
            
            if(check(a)) return true;
        }
        
        return false;
    }
    
    bool check(vector<int> &a) 
    {
        for(int i = 1; i < a.size(); i++) {
            if(a[i] <= a[i - 1]) return false;
        }
        
        return true;
    }
};
