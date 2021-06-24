class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        vector<int> a(101, 0);
        
        for(int i = 0; i < (int)size(ranges); i++) {
            int l = ranges[i][0], r = ranges[i][1];
            
            for(int j = l; j <= r; j++) a[j] = 1;
        }
        
        for(int i = left; i <= right; i++) {
            if(a[i] == 0) return false;
        }
        
        return true;
    }
};
