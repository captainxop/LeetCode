class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0) return false;
        n = pow(n);
        
        if(n != 1) return false;
        return true;
    }
    
    int pow(int n)
    {
        if(n == 1 || n % 2 == 1) 
            return n;
        
        return pow(n / 2);
    }
};
