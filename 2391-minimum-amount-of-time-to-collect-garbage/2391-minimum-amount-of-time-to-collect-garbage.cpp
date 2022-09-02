class Solution {
private:
    int collectionTime(vector<string> &garbage, vector<int> &travel, char truck) {
        int totalTime = 0, travelTime = 0;
        
        for(int i = 0; i < garbage.size(); i++) {
            bool ok = 0;
            
            for(auto &ch : garbage[i]) {
                if(ch == truck) {
                    totalTime++;
                    ok = 1;
                }
            }
            
            if(ok) {
                totalTime += travelTime;
                travelTime = 0;
            }
            
            if(i < travel.size()) {
                travelTime += travel[i];
            }
        }
        
        return totalTime;
    }
    
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int totalTime = collectionTime(garbage, travel, 'M') + collectionTime(garbage, travel, 'P') + collectionTime(garbage, travel, 'G');
        return totalTime;
    }
};