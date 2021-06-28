class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        int cnta[1001] = {0}, cntb[1001] = {0};
        
        for(int i = 0; i < (int)trust.size(); i++) {
            int u = trust[i][0], v = trust[i][1];
            cnta[u]++, cntb[v]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(cntb[i] == n - 1 && cnta[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};
