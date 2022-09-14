/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void countPseudoPalindromicPaths(TreeNode *root, vector<int> &cnt, int &ans) {
        if(root == NULL) {
            return;
        }
        
        cnt[root->val]++;
        countPseudoPalindromicPaths(root->left, cnt, ans);
        countPseudoPalindromicPaths(root->right, cnt, ans);
        
        if(root->left == NULL && root->right == NULL) {
            int oddCount = 0;
            for(int i = 1; i <= 9; i++) {
                oddCount += (cnt[i] % 2);
            }
            
            if(oddCount < 2) ans++;
        }
        
        cnt[root->val]--;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> cnt(10, 0);
        countPseudoPalindromicPaths(root, cnt, ans);
        return ans;
    }
};