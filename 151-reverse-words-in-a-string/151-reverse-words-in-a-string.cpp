class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> temp;
        
        while(ss >> word) {
            temp.push_back(word);
        }
        
        reverse(temp.begin(), temp.end());
        string ans;
        
        for(auto &str : temp) {
            ans += str + " ";
        }
        
        ans.pop_back();
        return ans;
    }
};