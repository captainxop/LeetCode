class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMinimum = INT_MAX, secondMinimum = INT_MAX;
        for(auto &x : nums) {
            if(x <= firstMinimum) firstMinimum = x;
            else if(x <= secondMinimum) secondMinimum = x;
            else return true;
        }
        
        return false;
    }
};