class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n = (int)size(chalk);
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL); // 10
        
        long long t = k / sum;
        long long a = sum * t; 
        
        k = k - a;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(k < chalk[i]) {
                ans = i;
                break;
            }
            else k -= chalk[i];
        }
        
        return ans;
    }
};
