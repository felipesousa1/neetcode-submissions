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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back({{root->val}});

        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++){
                TreeNode* current = q.front();
                if (current->left != nullptr){
                    v.push_back(current->left->val);
                    q.push(current->left);
                } 
                if (current->right != nullptr){
                    v.push_back(current->right->val);
                    q.push(current->right);
                } 
                q.pop();
            }
            if (!v.empty()) res.push_back(v);
        }
        
        return res;
    }
};
