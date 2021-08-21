class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> elms;
        int neg = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] < 0) neg++;
                elms.push_back(abs(matrix[i][j]));
            }
        }

        sort(elms.begin(), elms.end(), greater<int>());
        long long ans = 0;

        if (neg % 2 == 0)  {
            ans = accumulate(elms.begin(), elms.end(), 0LL);
        }
        else {
            ans = accumulate(elms.begin(), elms.end() - 1, 0LL);
            ans -= elms[size(elms) - 1];
        }

        return ans;
    }
};