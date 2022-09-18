class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, curr_len = 1;
        
        for(int i = 0; i < (int)s.size() - 1; i++) {
            if(s[i] == s[i + 1] - 1) {
                curr_len++;
            }
            else {
                ans = max(ans, curr_len);
                curr_len = 1;
            }
        }
        
        ans = max(ans, curr_len);
        return ans;
    }
};