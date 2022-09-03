class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size(), ans = 0;
        multiset<long long> s;
        long long cost = 0LL;
        
        for(int i = 0, j = 0; j < n; j++) {
            cost += runningCosts[j];
            s.insert(chargeTimes[j]);
            
            while(i <= j && !s.empty() && *(s.rbegin()) + (long long)(j - i + 1) * cost > budget) {
                cost -= runningCosts[i];
                s.erase(s.lower_bound(chargeTimes[i]));
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};