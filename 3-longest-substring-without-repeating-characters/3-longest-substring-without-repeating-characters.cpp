class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, bool> mp;  
        int i = 0, j = 0, ans = 0;
        
        while(j < s.size()) {
            if(mp[s[j]]) {
                ans = max(ans, j - i);
                
                while(i < j && s[i] != s[j]) {
                    mp[s[i]] = 0;
                    i++;
                }
                
                i++, j++;
            }
            else {
                mp[s[j]] = 1;
                j++;
            }
        }
        
        ans = max(ans, j - i);
        return ans;
    }
};