class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        int n = size(times);
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            map[times[i][0]] = i;
        }

        sort(times.begin(), times.end());

        vector<int> chair(n + 10, -1);

        for (int i = 0; i < n; i++) {
            int frnd = map[times[i][0]], j;

            for (j = 0; j < i; j++) {
                if (times[i][0] >= chair[j]) {
                    chair[j] = frnd;
                    break;
                }
            }

            chair[j] = times[i][1];

            if (frnd == targetFriend) {
                return j;
            }
        }

        return -1;
    }
};