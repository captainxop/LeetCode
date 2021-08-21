class Solution {
public:
	bool areOccurrencesEqual(string s) {
		unordered_map<char, int> cnt;
		for (int i = 0; i < size(s); i++) {
			cnt[s[i]]++;
		}

		set<int> res;

		for (auto it : cnt) {
			res.insert(it.second);
		}

		if (size(res) == 1) return true;
		return false;
	}
};