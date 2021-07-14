class Solution {
public:
    string customSortString(string order, string str) 
    {
        int cnt[26] = {0};
        string res;
        
        for(auto c : str) cnt[c - 'a']++;
        
        for(auto c : order) {
            while(cnt[c - 'a']-- > 0) {
                res.push_back(c);
            }
        }
        
        for(auto c : str) {
            while(cnt[c - 'a']-- > 0) {
                res.push_back(c);
            }
        }
        
        return res;
    }
};
