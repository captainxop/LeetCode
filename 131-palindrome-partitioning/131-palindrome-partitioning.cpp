class Solution {
private:
    vector<vector<string>> ans;
    set<vector<string>> set;
    
    void partitionHelper(string s, vector<bool> &cut, int i, int n) {
        if(i == n) {
            checkPartitions(s, cut, n);
            return;
        }
        
        partitionHelper(s, cut, i + 1, n);
                
        cut[i] = 1;
        partitionHelper(s, cut, i + 1, n);
        cut[i] = 0;
    }
    
    void checkPartitions(string &s, vector<bool> &cut, int n) {
        vector<string> temp;
        string str;
        
        for(int i = 0; i < n; i++) {
            if(cut[i] || i == n - 1) {
                str.push_back(s[i]);
                if(isPalindrome(str)) temp.push_back(str);
                else return;
                str = "";
            }
            else str.push_back(s[i]);
        }
        
        if(!set.count(temp)) {
            ans.push_back(temp);
            set.insert(temp);
        }
    }
    
    bool isPalindrome(string &s) {
        int n = (int)s.size();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        vector<bool> cut(n, 0);
        partitionHelper(s, cut, 0, n);
        return ans;
    }
};