class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        bool cnt[26] = {0};
        
        for(int i = 0; i < (int)sentence.size(); i++) {
            cnt[sentence[i] - 'a'] = 1;
        }
        
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) 
                return false;
        }
        
        return true;
    }
};
