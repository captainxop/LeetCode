class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_map<char, int> cnt;
        
        for(int i = 0; i < (int)jewels.size(); i++) {
            cnt[jewels[i]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < (int)stones.size(); i++) {
            if(cnt.count(stones[i])) {
                ans += cnt[stones[i]];
            }
        }
        
        return ans;
    }
};
