class Solution {
private:
    vector<string> ans;
    
    void helper(string &s, int i, int n) {
        if(i == n) {
            ans.push_back(s);
            return;
        }
        
        helper(s, i + 1, n);
        
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = toupper(s[i]);
            helper(s, i + 1, n);
            s[i] = tolower(s[i]);
        }
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        helper(s, 0, n);
        return ans;
    }
};