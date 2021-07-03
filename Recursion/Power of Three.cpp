class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0) 
            return false;
        
        n = pow(n);    
        
        return (n == 1);
    }
    
    int pow(int n)
    {
        if(n == 1 || n % 3 != 0)
            return n;
        
        return pow(n / 3);
    }
};

/*****Iterative*****/

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n < 1) 
            return false;
        
        while(n % 3 == 0)
            n /= 3;
        
        return (n == 1);
    }      
};
