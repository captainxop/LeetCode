//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private:
    int dp[1101][1101];

    bool helper(string &s, vector<string> &B, int n, int startIdx, int endIdx) {
        if(endIdx >= n) {
            return startIdx == endIdx;
        }
        if(dp[startIdx][endIdx] != -1) {
            return dp[startIdx][endIdx];
        }

        string word = s.substr(startIdx, endIdx - startIdx + 1);

        if(find(B.begin(), B.end(), word) != B.end()) {
            return dp[startIdx][endIdx] = helper(s, B, n, endIdx + 1, endIdx + 1) | helper(s, B, n, startIdx, endIdx + 1);
        }
        else {
            return dp[startIdx][endIdx] = helper(s, B, n, startIdx, endIdx + 1);
        }
    }
public:
    int wordBreak(string A, vector<string> &B) {
        int n = (int)A.size();
        // dp[i][j] = result for the string starting at ith index and ending at jth index
        memset(dp, -1, sizeof(dp));
        return helper(A, B, n, 0, 0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends