class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n < 1)
            return false;
        
        n = pow(n);
        
        return (n == 1);
    }
    
    int pow(int n)
    {
        if(n == 1 || n % 4 != 0)
            return n;
        
        return pow(n / 4);
    }
};

/***** Iterative *****/

class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n < 1)
            return false;
        
        while(n % 4 == 0)
            n /= 4;
        
        return (n == 1);
    }
};
