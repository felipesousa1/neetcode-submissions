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
    bool balanced = true;
    int height(TreeNode* node){
        if (node == nullptr) return 0;
        int lH = height(node->left);
        int rH = height(node->right);
        if (abs(lH-rH) > 1) balanced = false;

        return 1+max(lH, rH); 
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};
