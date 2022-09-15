class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int, greater<int>> mp;
        vector<int> original;
        
        for(auto &x : changed) {
            mp[x]++;
        }
        
        while(!mp.empty()) {
            auto it = mp.begin();
            int val = it->first;
            if(val % 2 == 1) return {};
            mp[val]--;
            if(mp[val / 2] == 0) return {};
            mp[val / 2]--;
            original.push_back(val / 2);
            
            if(mp[val] == 0) mp.erase(val);
            if(mp[val / 2] == 0) mp.erase(val / 2);
        }
        
        return original;
    }
};