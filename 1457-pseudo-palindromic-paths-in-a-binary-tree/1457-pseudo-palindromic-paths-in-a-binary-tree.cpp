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
    void countPseudoPalindromicPaths(TreeNode *root, int count, int &ans) {
        if(root == NULL) {
            return;
        }
        
        count = count ^ (1 << root->val); // toggle the bit
        
        if(root->left == NULL && root->right == NULL) {
            if((count & (count - 1)) == 0) { // to check atmoset 1 bit is set (power of 2)
                ans++;
            }
        }
        
        countPseudoPalindromicPaths(root->left, count, ans);
        countPseudoPalindromicPaths(root->right, count, ans);
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        countPseudoPalindromicPaths(root, 0, ans);
        return ans;
    }
};