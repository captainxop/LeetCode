class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        string str = "abcdefghijklmnopqrstuvwxyz";
        
        for(int i = 0; i < (int)str.size(); i++) {
            string temp;
            temp.push_back(str[i]);
            
            for(int j = i + 1; j < (int)str.size(); j++) {
                temp.push_back(str[j]);
                if(s.find(temp) != string::npos) {
                    ans = max(ans, (int)temp.size());
                }
            }
        }
        
        return ans;
    }
};