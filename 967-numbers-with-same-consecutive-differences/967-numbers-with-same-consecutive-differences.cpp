class Solution {
private:
    vector<int> ans;
    
    void helper(int n, int k, int idx, int num) {
        if(idx == n) {
            ans.push_back(num);
            return;
        }
        
        for(int i = 0; i <= 9; i++) {
            if(idx == 0 && i == 0) continue;
            if(idx == 0 || abs(num % 10 - i) == k) {
                helper(n, k, idx + 1, num * 10 + i);
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        helper(n, k, 0, 0);
        return ans;
    }
};