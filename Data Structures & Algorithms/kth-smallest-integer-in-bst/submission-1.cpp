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
    int cnt;
    int res = 0;

    void dfs(TreeNode* node){
        if (cnt == 0 || node == nullptr) return;
        
        dfs(node->left);

        cnt--;
        if (cnt == 0){
            res = node->val;
            return;
        }
        
        dfs(node->right);
    }
    
public: 
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return res;  
    }
};
