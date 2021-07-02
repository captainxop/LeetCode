class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s, 0 , s.size() - 1);
    }
    
    void reverse(vector<char> &s, int i, int j)
    {
        if(i >= j) return;
        
        char c = s[i];
        s[i++] = s[j];
        s[j--] = c;
        reverse(s, i, j);
    }
};

/***** Iterative *****/

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = (int)s.size();
        for(int i = 0; i < n / 2; i++) {
            swap(s[i], s[n-i-1]);
        }
    }
};
