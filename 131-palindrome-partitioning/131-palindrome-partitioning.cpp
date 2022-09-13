class Solution {
private:
    vector<vector<string>> ans;
    vector<string> list;
    
    void partitionHelper(string s, int idx, int n) {
        if(idx == n) {
            ans.push_back(list);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            if(isPalindrome(s, idx, i)) {
                list.push_back(s.substr(idx, i - idx + 1));
                partitionHelper(s, i + 1, n);
                list.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        partitionHelper(s, 0, n);
        return ans;
    }
};