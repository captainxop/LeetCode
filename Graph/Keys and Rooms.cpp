class Solution {
public:   
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = size(rooms);
        vector<bool> mark(n, false);
        stack<int> s;
        
        mark[0] = true;
        s.push(0);
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            
            for(int v : rooms[node]) {
                if(!mark[v]) {
                    mark[v] = true;
                    s.push(v);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!mark[i]) 
                return false;
        }
        
        return true;
    }
};
