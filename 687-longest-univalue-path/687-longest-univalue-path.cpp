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
    int longestUnivaluePathHelper(TreeNode* root, int &ans) {
        if(root == NULL) return 0;
        
        int left = longestUnivaluePathHelper(root->left, ans);
        int right = longestUnivaluePathHelper(root->right, ans);
        
        if((root->left == NULL || root->val == root->left->val) && (root->right == NULL || root->val == root->right->val)) {
            ans = max(ans, left + right);
            return max(left, right) + 1;
        }
        else if(root->left == NULL || root->val == root->left->val) {
            ans = max(ans, left);
            return left + 1;
        }
        else if(root->right == NULL || root->val == root->right->val) {
            ans = max(ans, right);
            return right + 1;
        }
        else {
            return 1;
        }
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        longestUnivaluePathHelper(root, ans);
        return ans;
    }
};