class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int ans = 0, balance = INT_MIN, n = accounts.size();
        
        for(int i=0; i<n; i++) {
            balance = 0;
            
            for(auto x : accounts[i]) {
                balance += x;
            }
            
            ans = max(ans, balance);
        }
        
        return ans;
    }
};
