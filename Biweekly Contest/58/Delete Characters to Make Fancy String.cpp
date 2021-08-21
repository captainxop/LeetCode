class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans.push_back(s[0]);
        int n = size(s), cnt = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;

                if (cnt == 3) {
                    cnt--;
                }
                else ans.push_back(s[i]);
            }
            else {
                cnt = 1;
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};