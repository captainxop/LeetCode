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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        int lv = 0;
        
        while(!q.empty()) {
            int sz = (int)q.size();
            deque<TreeNode*> dq;
            
            for(int i = 0; i < sz; i++) {
                TreeNode *curr = q.front();
                q.pop();
                
                if(lv % 2 == 1) dq.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(lv % 2) {
                while(!dq.empty()) {
                    swap(dq.front()->val, dq.back()->val);
                    dq.pop_front();
                    dq.pop_back();
                }
            }
            
            lv++;
        }
        
        return root;
    }
}; 