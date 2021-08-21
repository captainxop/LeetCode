class Solution {
public:
    int minTimeToType(string s) {
        int secs = 0;
        char c = 'a';

        for (int i = 0; i < size(s); i++) {
            secs += min(abs(s[i] - c), 26 - abs(s[i] - c));
            c = s[i];
        }

        return secs + size(s);
    }
};