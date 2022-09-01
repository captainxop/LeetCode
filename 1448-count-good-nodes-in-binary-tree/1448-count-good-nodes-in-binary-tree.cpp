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
    
    void countGoodNodes(TreeNode *root, int maxNode) {
        if(root == NULL) return;
        if(root->val >= maxNode) ans++;
        countGoodNodes(root->left, max(maxNode, root->val));
        countGoodNodes(root->right, max(maxNode, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        ans = 0;
        countGoodNodes(root, INT_MIN);
        return ans;
    }
};