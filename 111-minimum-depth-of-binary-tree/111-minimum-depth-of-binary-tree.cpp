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
    int ans;
    
    void minDepthHelper(TreeNode *root, int depth, int &ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            ans = min(ans, depth);
            return;
        }
        
        minDepthHelper(root->left, depth + 1, ans);
        minDepthHelper(root->right, depth + 1, ans);
    }
    
public:
    int minDepth(TreeNode* root) {
        ans = INT_MAX;
        if(root == NULL) return 0;
        minDepthHelper(root, 1, ans);
        return ans;
    }
};