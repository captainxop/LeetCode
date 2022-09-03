class Solution {
private:
    string convert(int n, int base) {
        string s;
        
        while(n) {
            int d = n % base;
            if(d >= 0 && d <= 9) s.push_back('0' + d);
            else s.push_back(d - 10 + 'A');
            n /= base;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
    
    bool isPalindrome(string &s) {
        int n = s.size();
        
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - i - 1]) return false;
        }
        
        return true;
    }
    
public:
    bool isStrictlyPalindromic(int n) {
        for(int base = 2; base <= n - 2; base++) {
            string s = convert(n, base);
            if(!isPalindrome(s)) return false;
        }
        
        return true;
    }
};