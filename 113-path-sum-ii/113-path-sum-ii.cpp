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
    vector<vector<int>> ans;
    
    void pathSumHelper(TreeNode *root, vector<int> &path, int sum, int targetSum) {
        if(root == NULL) return;
        
        path.push_back(root->val);
        sum += root->val;
        pathSumHelper(root->left, path, sum, targetSum);
        pathSumHelper(root->right, path, sum, targetSum);
        
        if(root->left == NULL && root->right == NULL && sum == targetSum) {
            ans.push_back(path);
        }
        
        path.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pathSumHelper(root, path, 0, targetSum);
        return ans;
    }
};