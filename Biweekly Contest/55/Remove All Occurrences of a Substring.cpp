class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        int n = part.length();
        
        while(1) {
            int find = s.find(part);
            
            if(find == string::npos) break;
            else{
                s.erase(find, n);
            }
        }
        
        return s;
    }
};
